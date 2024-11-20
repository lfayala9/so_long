/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:20:47 by layala-s          #+#    #+#             */
/*   Updated: 2024/11/18 11:03:21 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	// game.mlx_ptr = mlx_init();
	get_map(av[1], &game);
	count_objects(game.map, game.win_width, game.win_height, &game);
	validate_map(&game);
 	// game.mlx_win = mlx_new_window(game.mlx_ptr, game.win_width, \
	// 			game.win_height, "So_Long");
	// mlx_loop(game.mlx_ptr);
	// printf("height %d, width %d", game.win_height, game.win_width);
	return (0);
}
