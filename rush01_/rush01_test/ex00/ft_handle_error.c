/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hadle_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:37:58 by achigvin          #+#    #+#             */
/*   Updated: 2025/03/02 18:38:17 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printmatrix(int **matrix);
void	ft_assign(int *array, int *input_array);

int	ft_handle_error(const char *message, int len)
{
	write(1, message, len);
	return (0);
}
