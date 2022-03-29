#include <stdio.h>
#include <math.h>
#include <ncurses.h>

void draw_axis(void);
int scale_sin(float value);
void draw_line();

int main (void)
{
    int i;
    int row;
    char ch;

    initscr ();
    clear ();
    nodelay (stdscr, TRUE);	/* non block input for getch() */

    start_color ();
    init_pair (1, COLOR_WHITE, COLOR_BLUE);
    init_pair (2, COLOR_BLUE, COLOR_WHITE);
    init_pair (3, COLOR_RED, COLOR_WHITE);
    bkgd (COLOR_PAIR (3));
    curs_set(0);

    row = 10;
    noecho ();			/* stop echo of input */

    for (i = 0; i < 30; i++)
    {
        move (row, i);
        addstr ("Hello Ncurses");
        draw_line();
        refresh ();

        move (row, i);
        addstr ("             ");

        ch = getch ();
        if (ch == 'z')
        {
            row--;
            i = 0;
        }
    }
    nodelay (stdscr, FALSE);	/* non block input for getch() */

    getch ();
    endwin ();
}

void draw_line()
{
    int i;

    for (i=0; i<30; i++)
    {
        move(11,i);
        printw(" * ");
        refresh ();
        usleep(10000);
    }
    for (i=0; i<30; i++)
    {
        move(11,30-i);
        printw(" * ");
        refresh ();
        usleep(10000);
    }

}

void draw_axis(void){

}

int scale_sin(float value){

}