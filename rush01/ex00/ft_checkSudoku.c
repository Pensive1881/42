int ft_checkSudoku(int **matrix, int row, int col, int num) 
{
	int i;

	i = 0;
    while (i < 4) 
	{
        if (matrix[row][i] == num || matrix[i][col] == num) {
            return 0;
        }
		i++;
    }
    return 1;
}