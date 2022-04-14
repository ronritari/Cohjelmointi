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
#include <time.h>
#include <stdlib.h>
/***********************************************************************
 * VARIABLES AND CONSTANTS
 * *********************************************************************/
#define cell_amount_x 40
#define cell_amount_y 20
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
void print_current();
int user_int();
void replace_current();
void check_neigbour();
void input_cells_randomly(); 
void ncurses_start();
void ncurses_end();
/***********************************************************************
 * MAIN
 * *********************************************************************/
int main (void){
    struct cell board [cell_amount_y] [cell_amount_x] = {0, 0};
	
	printf("How many spaces would you like to occupy\nthe max is %d and the 1 will be placed randomly\n",cell_amount_y*cell_amount_x);

	input_cells_randomly(board);

	printf("how many generations would you like to print\n");
	int user_gen = user_int();

	ncurses_start();
	printw("generation number 1\n");
	print_current(board);
	refresh ();
	usleep(500000);
	
	for (int i=1; i<user_gen; i++){
		clear();
		check_neigbour(board);
		//printw("\n");
		//copies future to current
		replace_current(board);
		usleep(500000);
		printw("generation number %d\n",i+1);
		print_current(board);
		refresh ();
		usleep(500000);
		
		
	}
	ncurses_end();

}

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: print_current
 DESCRIPTION: prints current board at the start and also the next gen board
	Input: struct cell board[9][9]
	Output: none
 REMARKS when using this function:
**********************************************************************/                        
void print_current(struct cell board[cell_amount_y][cell_amount_x]){
	
	for(int y = 0; y < cell_amount_y; y++){
  		for(int x = 0; x < cell_amount_x; x++){
    		printw("%d",board[y][x].current);
		}
		printw("\n");
	}
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: print_current
 DESCRIPTION: prints current board at the start and also the next gen board
	Input: struct cell board[9][9]
	Output: none
 REMARKS when using this function:
**********************************************************************/         
int user_int(){
	int random_amount_user_input;
	scanf("%d" ,&random_amount_user_input);
	return random_amount_user_input;
}
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: print_current
 DESCRIPTION: prints current board at the start and also the next gen board
	Input: struct cell board[9][9]
	Output: none
 REMARKS when using this function:
**********************************************************************/     
void replace_current(struct cell board[cell_amount_y][cell_amount_x]){
	for(int y = 0; y < cell_amount_y; y++){
		for(int x = 0; x < cell_amount_x; x++){
			board[y][x].current = board[y][x].future;
		}
	}
}
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: print_current
 DESCRIPTION: prints current board at the start and also the next gen board
	Input: struct cell board[9][9]
	Output: none
 REMARKS when using this function:
**********************************************************************/  
void check_neigbour(struct cell board[cell_amount_y][cell_amount_x]){
	for(int y = 0; y < cell_amount_y; y++){
  		for(int x = 0; x < cell_amount_x; x++){
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
}
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: print_current
 DESCRIPTION: prints current board at the start and also the next gen board
	Input: struct cell board[9][9]
	Output: none
 REMARKS when using this function:
**********************************************************************/  
void input_cells_randomly(struct cell board[cell_amount_y][cell_amount_x]){
	srand(time(NULL));
	int user_cells = 0;
	user_cells = user_int();
	//puts 1 in random spaces also checks if space has already been occupied. loops amount of input
	for (int i = 0; i < user_cells; i++){
		int a,b;
		a = rand() %cell_amount_y;
		b = rand() %cell_amount_x;
		if(board[a][b].current != 1){
			board[a][b].current = 1;
		}else{
			i=i-1;
		}
	}
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: scale_sin
 DESCRIPTION: will give the value of sin compared to the limit of y scale
	Input: radian
	Output: scale + origo_y
  Used global variables:y_scale, origo_y
 REMARKS when using this function:
*********************************************************************/
void ncurses_start(){

    initscr(); // enables ncurses window state
    start_color(); // enables color

    init_pair (1, COLOR_BLACK, COLOR_WHITE);
    init_pair (2, COLOR_WHITE, COLOR_BLUE);

    bkgd (COLOR_PAIR (1)); // sets background and foreground color 
    refresh();

}
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: scale_sin
 DESCRIPTION: will give the value of sin compared to the limit of y scale
	Input: radian
	Output: scale + origo_y
  Used global variables:y_scale, origo_y
 REMARKS when using this function:
*********************************************************************/
void ncurses_end(){

    getch();
    endwin();

}
