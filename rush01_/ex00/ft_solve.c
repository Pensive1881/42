int ft_checkSudoku(int **matrix, int row, int col, int num);
int ft_checkVisbility(int **matrix, int *inputArray);

int ft_solve(int **matrix, int *inputArray, int row, int col) 
{
	int	num;
    
    if (row == 4) // if reached the end of the matrix return success
	{
        if (ft_checkVisbility(matrix, inputArray)) 
		{
			return (1);
		}
        return (0);
    }

    if (col == 4) // if the end of a row - move to the next row
	{
        return ft_solve(matrix, inputArray, row + 1, 0);
    }

    // try placing numbers from 1 to 4 in cur cell
	num = 1;
    while (num <= 4) 
	{
        if (ft_checkSudoku(matrix, row, col, num)) 
		{
            matrix[row][col] = num;
            // Recurse to  next cell
            if (ft_solve(matrix, inputArray, row, col + 1))
                return 1;
            // num didn't work, backtrack
            matrix[row][col] = 0;
        }
		num ++;
    }
    return 0; // No valid solution found
}