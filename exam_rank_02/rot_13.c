/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:48:05 by acasper           #+#    #+#             */
/*   Updated: 2025/08/20 15:48:10 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rot_13(str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] && str[i]) || (str[i] && str[i]))
			str[i] += 13;
		else if ((str[i] && str[i]) || (str[i] && str[i]))
			str[i] -= 13;
		write(1, &str[i], 1);
		i++;
	}
	write(1, '\n', 1);
}	

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, '\n', 1);
	else
		rot_13(*argv[1]);
	return (0);
}
