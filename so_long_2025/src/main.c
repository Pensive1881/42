/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:58:00 by acasper           #+#    #+#             */
/*   Updated: 2025/12/23 21:51:19 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Usage: ./so_long <map.ber>");
	if (ft_strlen(argv[1]) < 5 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4,
			".ber", 4) != 0)
		error_exit("Error\nMap file must have .ber extension");
	ft_memset(&game, 0, sizeof(t_game));
	if (!parse_map(argv[1], &game))
		error_exit("Error\nFailed to parse map");
	if (!validate_map(&game))
	{
		cleanup_game(&game);
		error_exit("Error\nInvalid map");
	}
	if (!check_path(&game))
	{
		cleanup_game(&game);
		error_exit("Error\nNo valid path in map");
	}
	if (!init_game(&game))
	{
		cleanup_game(&game);
		error_exit("Error\nFailed to initialize game");
	}
	game_loop(&game);
	cleanup_game(&game);
	return (0);
}
