Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int dig[10];
 	int i, j, k, num;
 	int is = 0, js = 0;
 	memset(dig, 0, sizeof(dig));

 	for (i = 0; i < boardRowSize; i++) //check the validation of rows first
 	{
 		for (j = 0; j < boardColSize; j++)
 		{
 			num = board[i][j] - 48;
 			if (num < 0)
 				continue;
 			else
 				dig[num]++;

 			if (dig[num] > 1)
 				return 0;
 		}
 		memset(dig, 0, sizeof(dig));
 	}

 	for (i = 0; i < boardColSize; i++) //check the validation of columns first
 	{
 		for (j = 0; j < boardRowSize; j++)
 		{
 			num = board[j][i] - 48;
 			if (num < 0)
 				continue;
 			else
 				dig[num]++;
 			
 			if (dig[num] > 1)
 				return 0;
 		}
 		memset(dig, 0, sizeof(dig));
 	}

 	for (k = 0; k < 9; k++) //check the cells
 	{
 		for (i = is; i < is + 3; i++)
 		{
 			for (j = js; j < js + 3; j++)
 			{
 				num = board[i][j] - 48;
	 			if (num < 0)
	 				continue;
	 			else
	 				dig[num]++;
	 			
	 			if (dig[num] > 1)
	 				return 0;
 			}
 		}
        memset(dig, 0, sizeof(dig));
 		is += 3;
 		if(is  > 6)
 		{
 			is = 0;
 			js += 3;
 		}
 	}
 	return 1;
}