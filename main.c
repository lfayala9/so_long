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

	if (!check_extension(av[1], ".ber"))
		exit(EXIT_FAILURE);
	get_map(av[1], &game);
	count_objects(game.map, game.win_width, game.win_height, &game);
	validate_map(&game);
	printf("exit pos y: %d\nexit pos x: %d\n", game.p_pos_y, game.p_pos_x);
	game.mlx_ptr = mlx_init();
 	game.mlx_win = mlx_new_window(game.mlx_ptr, game.win_width, \
				game.win_height, "So_Long");
	render_game(&game);
	mlx_loop(game.mlx_ptr);
	free_map(&game);
	return (0);
}
