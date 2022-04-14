/**********************************************************************
 * NAME 
 * Sin 
 * DESCRIPTION
 * this program will draw axes y and x and then print a sin line using ncurses
 * VERSION/DATE
 * Ron Ritari date 04/04/2022
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
#define PI 3.14159

#define max_screen_x 65
#define max_screen_y 30

#define origo_x max_screen_x/2
#define origo_y max_screen_y/2

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void draw_axis(void);
int scale_sin(float value);


/***********************************************************************
 * MAIN
 * *********************************************************************/
int main (void){
    initscr ();
    clear ();
    nodelay (stdscr, TRUE);	

    start_color ();
    init_pair (1, COLOR_WHITE, COLOR_BLUE);
    bkgd (COLOR_PAIR (1));
    draw_axis();

    float radian = -PI;

    for(int i=0; i<max_screen_x;i++){
        move(scale_sin(radian),i);
        printw("0");
        refresh ();
        usleep(5000);
        radian = radian + 0.1;
    }
    
    nodelay (stdscr, FALSE);
    getch ();
    endwin ();
}
/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: draw_axis
 DESCRIPTION: draws x and y axes by printing stars on the origo axes 
 assigned at the start definitions
	Input: none
	Output: none
  Used global variables: max_screen_x, origo_y, origo_x
 REMARKS when using this function:
*********************************************************************/
void draw_axis(void){

    for(int i = 0; i < max_screen_x; i++){
        move(origo_y, i);
        printw("*");
    
        move(i, origo_x);
        printw("*");

        refresh ();
        usleep(5000);
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
int scale_sin(float radian){

    int scale = origo_y * sin(radian);
    return scale + origo_y;

}


