#include "header.h"

int main(void)
{

	struct cell board[cell_amount_y][cell_amount_x] = {0, 0};

	file_or_random(board);

	printf("how many generations would you like to print\n");
	int user_gen = user_int();

	ncurses_start();

	for (int i = 1; i <= user_gen; i++)
	{
		clear();
		//printw("generation number %d\n", i);
		print_current(board);
		check_neigbour(board);
		// copies future to current
		replace_current(board);
		usleep(700000);
		refresh();
	}
	ncurses_end();
}

