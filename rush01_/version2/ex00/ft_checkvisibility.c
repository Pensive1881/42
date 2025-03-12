/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkvisibility.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsvelka <lsvelka@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:00:16 by lsvelka           #+#    #+#             */
/*   Updated: 2025/03/02 19:12:21 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_assign(int *array, int *inputArray)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		array[i] = inputArray[i];
		i++;
	}
}

int	ft_checkUp(int **matrix, int *up)
{
	int	i;
	int	j;
	int	max;
	int	count;

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
			return (0);
		j++;
	}
	return (1);
}

int	ft_checkDown(int **matrix, int *down)
{
	int	i;
	int	j;
	int	max;
	int	count;

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
			return (0);
		j++;
	}
	return (1);
}

int	ft_checkLeft(int **matrix, int *left)
{
	int	i;
	int	j;
	int	max;
	int	count;

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
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkRight(int **matrix, int *right)
{
	int	i;
	int	j;
	int	max;
	int	count;

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
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkvisbility(int **matrix, int *inputArray)
{
	int	up[4];
	int	down[4];
	int	left[4];
	int	right[4];

	ft_assign(up, inputArray);
	ft_assign(down, inputArray + 4);
	ft_assign(left, inputArray + 8);
	ft_assign(right, inputArray + 12);
	if (!ft_checkUp(matrix, up))
		return (0);
	if (!ft_checkDown(matrix, down))
		return (0);
	if (!ft_checkLeft(matrix, left))
		return (0);
	if (!ft_checkRight(matrix, right))
		return (0);
	return (1);
}
