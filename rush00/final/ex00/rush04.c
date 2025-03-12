/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarreir <sbarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:01:16 by sbarreir          #+#    #+#             */
/*   Updated: 2025/02/23 15:44:23 by apietsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
char	calc_output(int x, int y, int i, int j);

void	rush(int x, int y)
{
	int		row_index;
	int		column_index;
	char	output;

	if (x <= 0 || y <= 0)
		return ;
	row_index = 1;
	while (row_index <= y)
	{
		column_index = 1;
		while (column_index <= x)
		{
			output = calc_output(x, y, row_index, column_index);
			ft_putchar(output);
			column_index++;
		}
		ft_putchar('\n');
		row_index++;
	}
}

char	calc_output(int weight, int height, int row_index, int column_index)
{
	if (row_index == 1 && column_index == 1)
		return ('A');
	else if (row_index == 1 && column_index == weight)
		return ('C');
	else if (row_index == 1)
		return ('B');
	else if (row_index == height && column_index == 1)
		return ('C');
	else if (row_index == height && column_index == weight)
		return ('A');
	else if (row_index == height)
		return ('B');
	else if (column_index == 1 || column_index == weight)
		return ('B');
	else
		return (' ');
}
