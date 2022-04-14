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

 1.  NAME sin.c


 2.  DESCRIPTION  programme draws a sine wave 


 3.  VERSIONS
       Original:
         12.4.2022 / Dariush Moghadampour 

       Version history:

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <ncurses.h>
#include <unistd.h> 
#include <math.h>


/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */
#define MIN_X 0
#define MAX_X 60
#define MIN_Y 0
#define MAX_Y 30
#define PI 3.1459
#define MAX_SCREEN_X 60
#define MAX_SCREEN_Y 30
#define DESIRED_ORIGO_X MAX_SCREEN_X / 2
#define DESIRED_ORIGO_Y MAX_SCREEN_Y / 2
#define X_SCALE MAX_SCREEN_X / (2 * PI)
#define Y_SCALE -MAX_SCREEN_Y / 2
#define X_PAN DESIRED_ORIGO_X
#define Y_PAN DESIRED_ORIGO_Y


/* Global variables */

/* Global structures */


/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/

void draw_axis(void);
int scale_sin(float value);




/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main(void)
{
 float x;

    initscr();
    clear();

    start_color();
    init_pair(3, COLOR_BLUE, COLOR_WHITE);
    bkgd(COLOR_PAIR(3));
    curs_set(0);

    noecho(); /* stop echo of input */

    draw_axis();
    scale_sin(x);

    refresh();
    sleep(1);

    getch();
    endwin();
} /* end of main */

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/


/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: draw_axis
 DESCRIPTION: Function draws axis x an y simultaneously 
	Input:
	Output:
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

void draw_axis(void)
{
    int i = 0;

    for (i = 0; i < MAX_X; i++)
    {
        // X axis
        

        if (i == MAX_X -1)
        {
            move(MAX_Y / 2, i);
            printw(">");
        }

        else
        {
            move(MAX_Y / 2, i);
            printw("*");
        }

        // Y axis

        move(i / 2, MAX_X / 2);
        printw("*");
        usleep(1000);
        refresh();
    }
}



/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: scale_sin 
 DESCRIPTION: Function draws the sine wave 
	Input:
	Output:
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
 

 int scale_sin(float x)
{
    for (float x = -PI; x <= PI; x = x + 0.1)
    {
        float y;

        y = sin(x);
        move(y * Y_SCALE + Y_PAN, x * X_SCALE + X_PAN);

        printw("0");

        usleep(1000);
        refresh();
    }
}


