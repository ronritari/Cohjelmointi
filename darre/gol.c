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

 1.  NAME


 2.  DESCRIPTION


 3.  VERSIONS
       Original:
         5.3.2020 / juma

       Version history:

**********************************************************************/

/*-------------------------------------------------------------------*
 *    HEADER FILES                                                    *
 *--------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*-------------------------------------------------------------------*
 *    GLOBAL VARIABLES AND CONSTANTS                                  *
 *--------------------------------------------------------------------*/
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
void count_neighbours();

/*********************************************************************
 *    MAIN PROGRAM                                                      *
 **********************************************************************/

int main(void)
{
    struct cell board[9][9] = {0, 0};

    board[2][4].current = 1;
    board[3][4].current = 1;
    board[4][4].current = 1;

    int userint;
    printf("enter number of cycles:" ); 
    scanf("%d", &userint);

    for (int i = 0; i < userint; i++)
    {

        for (int y = 0; y < 9; y++)
        {

            for (int x = 0; x < 9; x++)
            {
                printf("%d", board[y][x].current);
            }
            printf("\n");
        }
        count_neighbours(board);

        printf("\n");
        printf("\n");

        for (int y = 0; y < 9; y++)
        {

            for (int x = 0; x < 9; x++)
            {
                board[y][x].current = board[y][x].future;
            }
        }
        
    }
} /* end of main */

/*********************************************************************
 *    FUNCTIONS                                                       *
 **********************************************************************/

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:
 DESCRIPTION:
    Input:
    Output:
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

void count_neighbours(struct cell board[9][9])
{

    for (int y = 0; y < 9; y++)
    {

        for (int x = 0; x < 9; x++)
        {
            int neigh = 0;

            if (board[y - 1][x - 1].current == 1)
            {

                neigh++;
            }
            if (board[y - 1][x].current == 1)
            {

                neigh++;
            }
            if (board[y - 1][x + 1].current == 1)
            {

                neigh++;
            }
            if (board[y][x - 1].current == 1)
            {

                neigh++;
            }
            if (board[y][x + 1].current == 1)
            {

                neigh++;
            }
            if (board[y + 1][x - 1].current == 1)
            {

                neigh++;
            }
            if (board[y + 1][x].current == 1)
            {

                neigh++;
            }
            if (board[y + 1][x + 1].current == 1)
            {

                neigh++;
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