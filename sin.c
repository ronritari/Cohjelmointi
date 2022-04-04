#include <stdio.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>

#define PI 3.14159

#define max_screen_x 60
#define max_screen_y 30

#define origo_x max_screen_x/2
#define origo_y max_screen_y/2

#define x_scale max_screen_x/(2*PI)
#define y_scale max_screen_y/2



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

void draw_axis(void){

    for(int i=0; i < max_screen_x; i++){
        move(origo_y, i);
        printw("*");

        move(i, origo_x);
        printw("*");

        refresh ();
        usleep(5000);
    }

}

int scale_sin(float value){

    int scale= y_scale* sin(value);
    return scale + origo_y;

}



