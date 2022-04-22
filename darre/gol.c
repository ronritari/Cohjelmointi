/***************************************************************************
 *   Copyright (C) $Year$ by $Author$   *
 *   $Email$   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME Game of life


 2.  DESCRIPTION  This game is a replica of John Conways game of life

    Game rules:

    * For a space that is 'populated':
    * Each cell with one or no neighbors' dies, as if by loneliness.
    * Each cell with four or more neighbors dies, as if by overpopulation.
    * Each cell with two or three neighbors survives.
    * For a space that is 'empty' or 'unpopulated'
    * Each cell with three neighbors becomes populated.


 3.  VERSIONS
       Original:
         20.4.2022 / Dariush Moghadampour

       Version history:

**********************************************************************/

/*-------------------------------------------------------------------*
 *    HEADER FILES                                                    *
 *--------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

/*-------------------------------------------------------------------*
 *    GLOBAL VARIABLES AND CONSTANTS                                  *
 *--------------------------------------------------------------------*/
#define cell_MAX_X 9
#define cell_MAX_Y 9

/* Control flags */

/* Global constants */

/* Global variables */

/* Global structures */
struct cell
{
    int current; /* current situation, which is visible on screen */
    int future;  /* temporary calculation area for next round calculation */
};

/*-------------------------------------------------------------------*
 *    FUNCTION PROTOTYPES                                             *
 *--------------------------------------------------------------------*/
void count_neighs();
void ncurses_start();
void ncurses_end();
void load_game_from_file();
/*********************************************************************
 *    MAIN PROGRAM                                                      *
 **********************************************************************/

int main(void)
{
    struct cell board[cell_MAX_Y][cell_MAX_X] = {0, 0};

    load_game_from_file(board);

    int userint;
    printf("enter number of cycles:");
    scanf("%d", &userint);

    ncurses_start();

    for (int i = 0; i < userint; i++)
    {
        clear();

        for (int y = 0; y < 9; y++)
        {

            for (int x = 0; x < 9; x++)
            {
                // printw("%d", board[y][x].current);

                if (board[y][x].current == 0)
                {
                    // printw("X");
                    attroff(COLOR_PAIR(2));
                    mvaddch(y, x, '0');
                    attron(COLOR_PAIR(2));
                }
                else if (board[y][x].current == 1)
                {
                    mvaddch(y, x, ' ');
                }
            }
            printw("\n");
        }
        count_neighs(board);

        printw("\n");
        printw("\n");

        for (int y = 0; y < 9; y++)
        {

            for (int x = 0; x < 9; x++)
            {
                board[y][x].current = board[y][x].future;
            }
        }
        usleep(700000);
        refresh();
    }
    ncurses_end();
} /* end of main */

/*********************************************************************
 *    FUNCTIONS                                                       *
 **********************************************************************/

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: count_neighs 
 DESCRIPTION: counts the neighbour cells 
    Input: board 
    Output: none 
  Used global variables: none 
 REMARKS when using this function: none
*********************************************************************/

void count_neighs(struct cell board[cell_MAX_Y][cell_MAX_X])
{

    for (int y = 0; y < 9; y++)
    {
        // printf("ok\n");
        for (int x = 0; x < 9; x++)
        {
            int neigh = 0;

            if (y - 1 >= 0 && x - 1 >= 0)
            {
                if ((board[y - 1][x - 1].current == 1))
                {
                    neigh++;
                }
            }
            if (y - 1 >= 0)
            {
                if ((board[y - 1][x].current == 1))
                {
                    neigh++;
                }
            }
            if (y - 1 >= 0 && x + 1 < cell_MAX_X)
            {
                if ((board[y - 1][x + 1].current == 1))
                {
                    neigh++;
                }
            }
            if (x - 1 >= 0)
            {
                if ((board[y][x - 1].current == 1))
                {
                    neigh++;
                }
            }
            if (x + 1 < cell_MAX_X)
            {
                if ((board[y][x + 1].current == 1))
                {
                    neigh++;
                }
            }
            if (y + 1 < cell_MAX_Y && x - 1 >= 0)
            {
                if ((board[y + 1][x - 1].current == 1))
                {
                    neigh++;
                }
            }
            if (y + 1 < cell_MAX_Y)
            {
                if ((board[y + 1][x].current == 1))
                {
                    neigh++;
                }
            }
            if (y + 1 < cell_MAX_Y && x + 1 < cell_MAX_X)
            {
                if ((board[y + 1][x + 1].current == 1))
                {
                    neigh++;
                }
            }

            if ((board[y][x].current == 1) && (neigh < 2))
            {
                board[y][x].future = 0;
            }

            else if ((board[y][x].current == 1) && (neigh > 3))
            {
                board[y][x].future = 0;
            }

            else if ((board[y][x].current == 0) && (neigh == 3))
            {
                board[y][x].future = 1;
            }

            else
            {
                board[y][x].future = board[y][x].current;
            }
        }
    }
}

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: load_game_from_file 
 DESCRIPTION: reads board from file and assings x and y values to the board
    Input: board 
    Output: none 
  Used global variables: none 
 REMARKS when using this function: none
*********************************************************************/

void load_game_from_file(struct cell board[cell_MAX_Y][cell_MAX_X])
{

    FILE *file;
    file = fopen("gol.txt", "r");

    if (file != NULL)
    {
        int x = 0;
        int y = 0;

        char c;

        for (int i = 0; !feof(file); i++)
        {

            fscanf(file, "%c", &c);

            if (c == '0')
            {
                x++;
            }

            if (c == '1')
            {
                board[x][y].current = 1;
                x++;
            }

            if (c == '\n')
            {
                x = 0;
                y++;
            }
        }
    }
    else
    {
        // if file is corrupted of dosent exist program will give a warning and end
        printf("FAILED TO READ FILE\n");
    }

    fclose(file);
}

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: ncurses_start
 DESCRIPTION: starts ncurses and initializes colours
    Input: none
    Output: none
 REMARKS when using this function: none 
*********************************************************************/

void ncurses_start()
{

    initscr();     // enables ncurses window state
    start_color(); // enables color

    init_pair(1, COLOR_RED, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_RED);

    bkgd(COLOR_PAIR(1)); // sets background and foreground color
    refresh();
}

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: ncurses_end
 DESCRIPTION: ends ncurses
    Input: none
    Output: none
 REMARKS when using this function: none
*********************************************************************/
void ncurses_end()
{

    getch();
    endwin();
}