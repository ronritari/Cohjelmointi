#include "header.h"
/*********************************************************************
 *    FUNCTIONS                                                       *
 **********************************************************************/

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: print_current
 DESCRIPTION: prints current board at the start and also the next gen board
 it also replaces zeros with dots and ones with zeroes
    Input: struct cell board[cell_amount_y][cell_amount_x]
    Output: none
 REMARKS when using this function:
**********************************************************************/
void print_current(struct cell board[cell_amount_y][cell_amount_x])
{
    int x;
    int y;
    for (y = 0; y < cell_amount_y; y++)
    {
        for (x = 0; x < cell_amount_x; x++)
        {

            /* checks if cell is 0 or 1*/
            if (board[y][x].current == 0)
            {

                attroff(COLOR_PAIR(2));
                mvaddch(y, x, '.');
                attron(COLOR_PAIR(2));
            }
            else if (board[y][x].current == 1)
            {

                mvaddch(y, x, ' ');
            }
        }
        printw("\n");
    }
}

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: user_int
 DESCRIPTION: asks user for an integer and returns its value
    Input: replace_current(struct cell board[cell_amount_y][cell_amount_x]
    Output: random_amount_user_input
 REMARKS when using this function: i am asuming integer will be put in will crash if not
**********************************************************************/
int user_int()
{
    int random_amount_user_input;
    scanf("%d", &random_amount_user_input);
    return random_amount_user_input;
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: replace_current
 DESCRIPTION: replaces current board with future board so it loops
    Input: replace_current(struct cell board[cell_amount_y][cell_amount_x]
    Output: none
 REMARKS when using this function:
**********************************************************************/
void replace_current(struct cell board[cell_amount_y][cell_amount_x])
{
    int y;
    int x;
    for (y = 0; y < cell_amount_y; y++)
    {
        for (x = 0; x < cell_amount_x; x++)
        {
            board[y][x].current = board[y][x].future;
        }
    }
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: check_neigbour
 DESCRIPTION: checks neighbour and adds cells neighbours together
 also creates the future board
    Input: replace_current(struct cell board[cell_amount_y][cell_amount_x]
    Output: none
 REMARKS when using this function:
**********************************************************************/
void check_neigbour(struct cell board[cell_amount_y][cell_amount_x])
{
    int y;
    int x;
    for (y = 0; y < cell_amount_y; y++)
    {
        for (x = 0; x < cell_amount_x; x++)
        {
            /* keeps record of cells neighbours*/
            int neighbour = 0;
            /* checks firs if cell is within boarder and that the cell around is alive*/
            if (y - 1 >= 0 && x - 1 >= 0)
            {
                if ((board[y - 1][x - 1].current == 1))
                {
                    neighbour++;
                }
            }
            if (y - 1 >= 0)
            {
                if ((board[y - 1][x].current == 1))
                {
                    neighbour++;
                }
            }
            if (y - 1 >= 0 && x + 1 < cell_amount_x)
            {
                if ((board[y - 1][x + 1].current == 1))
                {
                    neighbour++;
                }
            }
            if (x - 1 >= 0)
            {
                if ((board[y][x - 1].current == 1))
                {
                    neighbour++;
                }
            }
            if (x + 1 < cell_amount_x)
            {
                if ((board[y][x + 1].current == 1))
                {
                    neighbour++;
                }
            }
            if (y + 1 < cell_amount_y && x - 1 >= 0)
            {
                if ((board[y + 1][x - 1].current == 1))
                {
                    neighbour++;
                }
            }
            if (y + 1 < cell_amount_y)
            {
                if ((board[y + 1][x].current == 1))
                {
                    neighbour++;
                }
            }
            if (y + 1 < cell_amount_y && x + 1 < cell_amount_x)
            {
                if ((board[y + 1][x + 1].current == 1))
                {
                    neighbour++;
                }
            }

            /* Cell dies due to under population*/
            if ((board[y][x].current == 1) && (neighbour < 2))
            {
                board[y][x].future = 0;
            }
            /* Cell dies due to over population*/
            else if ((board[y][x].current == 1) && (neighbour > 3))
            {
                board[y][x].future = 0;
            }
            /* A new cell is born*/
            else if ((board[y][x].current == 0) && (neighbour == 3))
            {
                board[y][x].future = 1;
            }
            /* Remains the same*/
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
 NAME: input_cells_randomly
 DESCRIPTION: assings cells in random positions amount is determined by user
    Input: replace_current(struct cell board[cell_amount_y][cell_amount_x]
    Output: none
 REMARKS when using this function:
**********************************************************************/
void input_cells_randomly(struct cell board[cell_amount_y][cell_amount_x])
{
    int i;
    int user_cells;

    printf("How many spaces would you like to occupy\nthe max is %d and the living cells will be placed randomly\n", cell_amount_y * cell_amount_x);
    srand(time(NULL));
    /* asks for user integer*/
    user_cells = user_int();

    /* puts 1 in random spaces also checks if space has already been occupied. loops amount of input*/
    
    for (i = 0; i < user_cells; i++)
    {
        int a, b;
        a = rand() % cell_amount_y;
        b = rand() % cell_amount_x;
        if (board[a][b].current != 1)
        {
            board[a][b].current = 1;
        }
        /* if cell is alredy 1 it takes an extra loop*/
        else
        {
            i = i - 1;
        }
    }
}

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: ncurses_start
 DESCRIPTION: starts ncurses and initializes colours
    Input: none
    Output: none
 REMARKS when using this function:
*********************************************************************/
void ncurses_start()
{

    initscr();     /* enables ncurses window state*/
    start_color(); /*enables color*/

    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);

    bkgd(COLOR_PAIR(1)); /* sets background and foreground color*/
    refresh();
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: ncurses_end
 DESCRIPTION: ends ncurses
    Input: none
    Output: none
 REMARKS when using this function:
*********************************************************************/
void ncurses_end()
{

    getch();
    endwin();
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: load_game_from_file
 DESCRIPTION: reads pre made board from file and assings x and y values to the board
    Input: replace_current(struct cell board[cell_amount_y][cell_amount_x]
    Output: none
 REMARKS when using this function:
*********************************************************************/
void load_game_from_file(struct cell board[cell_amount_y][cell_amount_x])
{
    FILE *file;
    file = fopen("file.txt", "r");
    

    if (file != NULL)
    {
        int x = 0;
        int y = 0;

        char c;
        int i;
        for (i = 0; !feof(file); i++)
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
        /* if file is corrupted of dosent exist program will give a warning and end*/
        printf("FAILED TO READ FILE\n");
        ncurses_end();
    }

    fclose(file);
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: scale_sin
 DESCRIPTION: asks user to either read file or randomly assign cells
 the decision will go to either load_game_from_file or input_cells_randomly
 it will ask until answer is either 1 or 2
    Input: struct cell board[cell_amount_y][cell_amount_x]
    Output:
 REMARKS when using this function:
*********************************************************************/
void file_or_random(struct cell board[cell_amount_y][cell_amount_x])
{

    printf("Would you like to use a pre-made board or randomize the cells?\npress 1 to read from file\npress 2 to randomize cells\n");
    switch (user_int())
    {
    case 1:
        load_game_from_file(board);
        break;
    case 2:
        input_cells_randomly(board);
        break;

    default:
        printf("try again\n");
        file_or_random(board);
        break;
    }
}
