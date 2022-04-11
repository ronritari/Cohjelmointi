/**********************************************************************
 * NAME 
 * Game of Life
 * DESCRIPTION
 * 
 * VERSION/DATE
 * Ron Ritari date 11/04/2022
 * *********************************************************************/

/***********************************************************************
 * FILES
 * *********************************************************************/
#include <stdio.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>
/***********************************************************************
 * VARIABLES AND CONSTANTS
 * *********************************************************************/

/***********************************************************************
 * STRUCTURES
 * *********************************************************************/
struct cell{
	int current;  /* current situation, which is visible on screen */
	int future;   /* temporary calculation area for next round calculation */
};

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void print_start();


/***********************************************************************
 * MAIN
 * *********************************************************************/
int main (void){
    struct cell board [9] [9] = {0, 0};
	//hardcoded 1(place random numbers)
	board[2][2].current = 1;
	board[3][2].current = 1;
	board[4][2].current = 1;
	print_start(board);
	//prints next gen twice (swich to user input)
	for (int i=0; i<2; i++){
		//print board
		for(int y = 0; y < 9; y++){
  			for(int x = 0; x < 9; x++){
    			

				int points = 0;

				if(board[y-1][x-1].current == 1){
					points++;
				} if(board[y-1][x].current == 1){
					points++;
				} if(board[y-1][x+1].current == 1){
					points++;
				} if(board[y][x-1].current == 1 ){
					points++;
				} if(board[y][x+1].current == 1){
					points++;
				} if(board[y+1][x-1].current == 1){
					points++;
				} if(board[y+1][x].current == 1){
					points++;
				} if(board[y+1][x+1].current == 1){
					points++;
				}
				//printf("%d\n",points);
				// Cell dies due to under population
				if ((board[y][x].current == 1) && (points < 2)){
                	board[y][x].future = 0;
				}
                // Cell dies due to over population
            	else if ((board[y][x].current == 1) && (points > 3)){
                	board[y][x].future  = 0;
				}
                // A new cell is born
            	else if ((board[y][x].current == 0) && (points == 3)){
                	board[y][x].future  = 1;
				}
                // Remains the same
            	else{
                	board[y][x].future = board[y][x].current;
				}
 			}
		}
		printf("\n");
		//copies future to current
		for(int y = 0; y < 9; y++){
  			for(int x = 0; x < 9; x++){
				board[y][x].current = board[y][x].future;
			}
		}
		//prints next gen
		for(int y = 0; y < 9; y++){
  			for(int x = 0; x < 9; x++){
    			printf("%d",board[y][x].current);
			}
			printf("\n");
		}
		//printf("\n");

	}

}

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: print_start
 DESCRIPTION: 
	Input: none
	Output: none
 REMARKS when using this function:
**********************************************************************/                        
void print_start(struct cell board[9][9]){
	
	for(int y = 0; y < 9; y++){
  		for(int x = 0; x < 9; x++){
    		printf("%d",board[y][x].current);
		}
		printf("\n");
	}
	

}