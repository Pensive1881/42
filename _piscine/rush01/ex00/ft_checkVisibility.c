void ft_assign(int *array, int *inputArray)
{
    int i;

    i = 0;
    while (i < 4) {
        array[i] = inputArray[i];
        i++;
    }
}

int	ft_checkVisbility(int **matrix, int *inputArray){
	int up[4];
	int down[4];
	int left[4];
	int right[4];

	ft_assign(up, inputArray);
	ft_assign(down, inputArray + 4);
	ft_assign(left, inputArray + 8);
	ft_assign(right, inputArray + 12);

	int i; //row
    int j; //column
    int max;
    int count; // our visibility
//up
    j = 0;
    while (j < 4)
    {
        max = 0;
        count = 0;
        i = 0;
        while (i < 4)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
                count++;
            }
            i++;
        }
        if (count != up[j])
                return (0); // error
        j++;
    }
//down
    j = 0;
    while (j < 4)
    {
        max = 0;
        count = 0;
        i = 3;
        while (i >= 0)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
                count++;
            }
            i--;
        }
        if (count != down[j])
                return (0); // error
        j++;
    }
//left
    i = 0;
    while (i < 4)
    {
        max = 0;
        count = 0;
        j = 0;
        while (j < 4)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
                count++;
            }
            j++;
        }
        if (count != left[i])
                return (0); // error
        i++;
    }
//right
    i = 0;
    while (i < 4)
    {
        max = 0;
        count = 0;
        j = 3;
        while (j >= 0)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
                count++;
            }
            j--;
        }
        if (count != right[i])
                return (0); // error
        i++;
    }
	return (1);
}