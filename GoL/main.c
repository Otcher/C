#include <stdio.h>
#include <stdlib.h>

#ifdef __unix__
#define CLEAR_COMMAND "clear"
#elif defined(_WIN32) || defined(WIN32) 
#define CLEAR_COMMAND "cls"
#endif

#define BOARD_SIZE 50
#define GAME_SPEED_IN_MS 200

typedef enum {DEAD = 0, ALIVE} cell_status;
typedef enum { FALSE = 0, TRUE } boolean;

/*
	Nothing special here, just going through the array and printing every cell's status as explained below:
	'.' = DEAD
	'X' = ALIVE
*/

void PrintCells(int board[][BOARD_SIZE])
{
	for (int y = 0; y < BOARD_SIZE;y++)
	{
		for (int x= 0; x < BOARD_SIZE; x++)
		{
			if (board[x][y] == ALIVE) printf("%c", 'X');
			else printf("%c", '.');
		}
		printf("%c", '\n');
	}
}

/*
	Calculate the amount of alive cells around a specific cell
	So I can use the data to detemine underpopulation, overpopulation, birth conditions
	or basically if to kill, keep or give birth to a specific cell.
*/

int GetCellSum(int board[][BOARD_SIZE], int x, int y)
{
	int sum = 0;
	for (int i = (x-1); i <= (x+1); i++)
	{
		for (int j = (y-1); j <= (y+1); j++)
		{
			if (i == x && j == y) continue;
			if (x >= 0 && y >= 0 && x < BOARD_SIZE && y < BOARD_SIZE)
			{
				sum += board[i][j];
			}
		}
	}

	return sum;
}

int main()
{
	int board[BOARD_SIZE][BOARD_SIZE];
	int newBoard[BOARD_SIZE][BOARD_SIZE];
	memset(board, DEAD, sizeof(board));
	memset(newBoard, DEAD, sizeof(newBoard));

	/*
		Initializing the board with example cells
	*/

	board[20][20] = ALIVE;
	board[21][20] = ALIVE;
	board[22][20] = ALIVE;
	board[24][20] = ALIVE;
	board[20][21] = ALIVE;
	board[23][22] = ALIVE;
	board[24][22] = ALIVE;
	board[21][23] = ALIVE;
	board[22][23] = ALIVE;
	board[24][23] = ALIVE;
	board[20][24] = ALIVE;
	board[22][24] = ALIVE;
	board[24][24] = ALIVE;

	/*------------------------------
		Game Loop
	------------------------------*/
	PrintCells(board);

	boolean finished = FALSE;
	
	while (finished == FALSE)
	{
		memcpy(newBoard, board, sizeof(board));
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			for (int x = 0; x < BOARD_SIZE; x++)
			{
				/*Check if the cell is located in a problematic location (e.g [0, something] or [something, BOARD_SIZE]*/
				int sum = GetCellSum(board, x, y);
				if (board[x][y] == ALIVE)
				{
					/*Check if lonely or overcrowded then kill, if not then keep the cell alive*/
					if (sum < 2 || sum > 3)
					{
						newBoard[x][y] = DEAD;
					}
				}
				else
				{
					/*Check if its a boy or a girl (kidding, check if there is a baby to deliver or not)*/
					if(sum == 3)
						newBoard[x][y] = ALIVE;
				}
			}
		}

		if (memcmp(board, newBoard, sizeof(board)) == 0)
			finished = TRUE;
		
		/*Copy the new board to the old one*/
		memcpy(board, newBoard, sizeof(newBoard));

		system(CLEAR_COMMAND);
		PrintCells(board);
		_sleep(GAME_SPEED_IN_MS);
	}
	return 0;
}