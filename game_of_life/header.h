/**********************************************************************
 * NAME
 * Game of Life
 *
 * DESCRIPTION
 * this game is a version of john conways game of life
 * the rules as follows:
 *
 * For a space that is 'populated':
 * Each cell with one or no neighbors' dies, as if by loneliness.
 * Each cell with four or more neighbors dies, as if by overpopulation.
 * Each cell with two or three neighbors survives.
 *
 * For a space that is 'empty' or 'unpopulated'
 * Each cell with three neighbors becomes populated.
 *
 * VERSION/DATE/
 * Ron Ritari date 14/04/2022
 * *********************************************************************/

/***********************************************************************
 * FILES
 * *********************************************************************/
#include <stdio.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
/***********************************************************************
 * VARIABLES AND CONSTANTS
 * *********************************************************************/
#define cell_amount_x 10
#define cell_amount_y 10
/***********************************************************************
 * STRUCTURES
 * *********************************************************************/
struct cell
{
	int current; /* current situation, which is visible on screen */
	int future;	 /* temporary calculation area for next round calculation */
};

/*-------------------------------------------------------------------*
 *    FUNCTION PROTOTYPES                                             *
 *--------------------------------------------------------------------*/
void print_current();
int user_int();
void replace_current();
void check_neigbour();
void input_cells_randomly();
void ncurses_start();
void ncurses_end();
void load_game_from_file();
void file_or_random();
