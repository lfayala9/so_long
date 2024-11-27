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

void	render_background(t_game *game, void **object, char *path)
{
	int		y;
	int		x;
	int		img_width;
	int		img_height;
	
	*object = mlx_xpm_file_to_image(game->mlx_ptr, path, &img_width, &img_height);
	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, *object, x, y);
			x += 32;
		}
		y += 32;
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	if (!check_extension(av[1], ".ber"))
		exit(EXIT_FAILURE);
	get_map(av[1], &game);
	count_objects(game.map, game.win_width, game.win_height, &game);
	validate_map(&game);
	game.mlx_ptr = mlx_init();
 	game.mlx_win = mlx_new_window(game.mlx_ptr, game.win_width, \
				game.win_height, "So_Long");
	render_background(&game, (void **)&game.background, "./assets/ground.xpm");
	mlx_loop(game.mlx_ptr);
	free_map(&game);
	return (0);
}
