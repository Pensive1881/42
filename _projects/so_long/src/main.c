/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:22:36 by acasper           #+#    #+#             */
/*   Updated: 2026/02/26 14:52:19 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	exit_clean(t_game *g, const char *msg)
{
	cleanup_game(g);
	error_exit(msg);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Usage: ./so_long <map.ber>");
	if (ft_strlen(argv[1]) < 5 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4,
			".ber", 4) != 0)
		error_exit("Map file must have .ber extension");
	ft_memset(&game, 0, sizeof(t_game));
	if (!parse_map(argv[1], &game))
		exit_clean(&game, "Failed to parse map");
	if (!validate_map(&game))
		exit_clean(&game, "Failed to validate map");
	if (!check_path(&game))
		exit_clean(&game, "No valid path in map");
	if (!init_game(&game))
		exit_clean(&game, "Failed to initialize game");
	game_loop(&game);
	cleanup_game(&game);
	return (0);
}
