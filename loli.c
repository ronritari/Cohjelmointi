void check_neigbour(struct cell board[cell_amount_y][cell_amount_x])
{
	for (int y = 0; y < cell_amount_y; y++)
	{
		for (int x = 0; x < cell_amount_x; x++)
		{
			// keeps record of cells neighbours
			int neighbour = 0;
			// checks firs if cell is within boarder and that the cell around is alive
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

			// Cell dies due to under population
			if ((board[y][x].current == 1) && (neighbour < 2))
			{
				board[y][x].future = 0;
			}
			// Cell dies due to over population
			else if ((board[y][x].current == 1) && (neighbour > 3))
			{
				board[y][x].future = 0;
			}
			// A new cell is born
			else if ((board[y][x].current == 0) && (neighbour == 3))
			{
				board[y][x].future = 1;
			}
			// Remains the same
			else
			{
				board[y][x].future = board[y][x].current;
			}
		}
	}
}