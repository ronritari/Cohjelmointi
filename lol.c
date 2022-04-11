#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

/* Width size factor */
#define WFAC 3

/* Universe loop */
#define ULOOP(i, j, b)  for(i = b; i < S; ++i) \
                             for(j = b; j < (S * WFAC); ++j)

/* Make universe table */
#define UMAKE(U)                                           \
     do {                                                  \
          U = calloc(S + 1, sizeof(char *));               \
          for(i = 0; i < S + 1; ++i)                       \
              U[i] = calloc((S * WFAC) + 1, sizeof(char)); \
     } while(/* CONSTCOND */ 0)

/* Free universe table */
#define UFREE(U)                 \
     do {                        \
          for(i = 0; i < S; ++i) \
               free(U[i]);       \
          free(U);               \
          U = NULL;              \
     } while(/* CONSTCOND */ 0)

/* Cell state */
enum { Dead = 0, Live };

/* Ω - U N I V E R S E - Ω */
char **u = NULL;

/* Ω size */
int S = 30;

/* Generation / Population */
unsigned long generation = 0;
long population = 0;

/* Prog state */
long timing = 100000;
int running = 1;
int pa = 1;
int insert = 1;

/* Insertion cursor position */
int px, py;

/* Interface window */
WINDOW *wui;

void
init(void)
{
     int i, bg = COLOR_BLACK;

     /* Init ncurses */
     initscr();
     noecho();
     raw();
     keypad(stdscr, TRUE);
     nodelay(stdscr, TRUE);
     curs_set(FALSE);
     start_color();
     clear();

     if(use_default_colors() == OK)
          bg = -1;

     init_pair(0, COLOR_WHITE, COLOR_BLACK);
     init_pair(1, bg, COLOR_GREEN);
     init_pair(2, COLOR_BLACK, COLOR_BLACK);
     init_pair(3, COLOR_BLACK, COLOR_WHITE);
     init_pair(4, COLOR_GREEN, bg);
     init_pair(5, COLOR_RED, bg);

     wui = newwin(1, COLS, LINES - 1, 0);
     wmove(wui, 0, 0);
     wrefresh(wui);

     refresh();

     /* Alloc universe */
     UMAKE(u);

     /* Base position of cursor */
     px = py = S / 2;

     return;
}

void
refreshU(void)
{
     int i, j, c = 0;

     ULOOP(i, j, 0)
     {
          attron(u[i][j] ? COLOR_PAIR(2) : COLOR_PAIR(3));

          if(insert && py == i && px == j)
               attron(COLOR_PAIR(1));

          mvaddstr(i, j, "0");

          if(insert && py == i && px == j)
               attroff(COLOR_PAIR(1));

          attroff(u[i][j] ? COLOR_PAIR(2) : COLOR_PAIR(3));
     }

     refresh();

     return;
}

/* Conway's game of life core: */
void
cellprocess(void)
{
     int i, j, l = 0;
     int a, b, c;
     char **nextu = NULL;

     if(pa)
          return;

     UMAKE(nextu);

     ULOOP(i, j, 1)
     {
          /* Remove selected cell (u[i][j]) of count */
          l = -(u[i][j]);

          for(a = -1; a < 2; ++a)
               for(b = -1; b < 2; ++b)
                    if(u[i + a][j + b])
                         ++l;

          /* 3 cells living around the selected */
          if(l == 3)
               nextu[i][j] = Live;     /* Born or keep alive */

          /* 2 cells living around */
          else if(l == 2)
               nextu[i][j] = u[i][j]; /* Keep same state */

          /* <2 or >3 cells living around */
          else
               nextu[i][j] = Dead;    /* Die */
     }

     /* Copy next universe in current and count population */
     population = 0;

     ULOOP(i, j, 0)
          population += ((u[i][j] = nextu[i][j])) ? 1 : 0;

     UFREE(nextu);

     ++generation;

     usleep(timing);

     return;
}

void
resizeU(int s)
{
     int i, j;
     char **nextu = NULL;

     /* Temp universe to save current and resize it */
     UMAKE(nextu);

     ULOOP(i, j, 0)
          nextu[i][j] = u[i][j];

     UFREE(u);

     S = s;

     /* Alloc universe */
     UMAKE(u);

     ULOOP(i, j, 0)
          u[i][j] = nextu[i][j];

     UFREE(nextu);
     clear();

     /* Adapt cursor position */
     if(px > (S * WFAC) - 1)
          px = (S * WFAC) - 1;
     if(py > S - 1)
          py = S - 1;

     return;
}

void
key_event(void)
{
     int i, c, j;

     switch((c = getch()))
     {
     /* Insertion cursor movement {{{ */
     case KEY_UP:
     case 'k':
     case 'K':
          if(insert && py > 0)
               --py;
          break;

     case KEY_DOWN:
     case 'j':
     case 'J':
          if(insert && py < S - 1)
               ++py;
          break;

     case KEY_LEFT:
     case 'h':
     case 'H':
          if(insert && px > 0)
               --px;
          break;

     case KEY_RIGHT:
     case 'l':
     case 'L':
          if(insert && px < (S * WFAC) - 1)
               ++px;
          break;
     /* }}} */

     /* Quit */
     case 'q':
     case 'Q':
          running = 0;
          break;

     /* Pause game */
     case 'p':
     case 'P':
          pa = !pa;
          break;

     /* Insert mode switch */
     case 'i':
     case 'I':
     case KEY_IC:
          insert = !insert;
          break;

     /* Clean universe */
     case 'c':
     case 'C':
          ULOOP(i, j, 0)
               u[i][j] = 0;

          generation = population = 0;
          pa = insert = 1;
          break;

     /* Reverse selected cells state */
     case ' ':
          if(insert)
               u[py][px] = !u[py][px];
          break;

     /* Generation timing */
     case '+':
          if(timing - 5000)
               timing -= 5000;
          break;

     case '-':
          if(timing < 600000)
               timing += 5000;
          break;

     /* Resize universe */
     case KEY_PPAGE:
          if(S <= 2000)
               resizeU(S + 1);
          break;

     case KEY_NPAGE:
          if(S > 3)
               resizeU(S - 1);
          break;

     case KEY_RESIZE:
          clear();
          break;

     default:
          break;
     }

     return;
}

void
draw_ui(void)
{
     int i;

     /* Clean win */

     wrefresh(wui);

     werase(wui);

     wattron(wui, COLOR_PAIR(0));

     /* wmove(wui, 0, 0);*/


     /* Universe state */
     wattron(wui, COLOR_PAIR(pa ? 5 : 4) | A_BOLD);
     wprintw(wui, pa ? "[PAUSED]  " : "[RUNNING] ");
     wattroff(wui, COLOR_PAIR(pa ? 5 : 4) | A_BOLD);

     /* General info */
     wprintw(wui, "[Generation: %.6d  Population: %.5d  Timing(+/-): %.6dµs] ",
               generation, population, timing);

     /* Insert mode with info for current position */
     if(insert)
          wprintw(wui, "Insert [%.4dx%.4d] (%s)", px, py, ((u[py][px]) ? "Live" : "Dead"));

     wattroff(wui, COLOR_PAIR(0));

     wrefresh(wui);

     return;
}

/*
 *  \    /\    /
 *   )  ( ')  < Maaaain!
 *  (  /  )    \
 *   \(__)|
 */
int
main(int argc, char **argv)
{
     int i;

     init();

     /* Main loop */
     while(running)
     {
          cellprocess();
          key_event();
          refreshU();
          draw_ui();
     }

     endwin();
     UFREE(u);

     return 0;
}


int a[];
int a[];

int a[][];