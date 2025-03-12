/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_visbility1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamedin <mhamedin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:51:25 by mhamedin          #+#    #+#             */
/*   Updated: 2025/03/02 15:53:18 by mhamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_right(int **matrix, int *right);
int	ft_check_left(int **matrix, int *left);
int	ft_check_down(int **matrix, int *down);
int	ft_check_up(int **matrix, int *up);
int	ft_assign(int *array, int *inputArray);

int	ft_check_visbility(int **matrix, int *inputArray)
{
	int	up[4];
	int	down[4];
	int	left[4];
	int	right[4];

	ft_assign(up, inputArray);
	ft_assign(down, inputArray + 4);
	ft_assign(left, inputArray + 8);
	ft_assign(right, inputArray + 12);
	if (!ft_check_up(matrix, up))
		return (0);
	if (!ft_check_down(matrix, down))
		return (0);
	if (!ft_check_left(matrix, left))
		return (0);
	if (!ft_check_right(matrix, right))
		return (0);
	return (1);
}
