/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:52:56 by layala-s          #+#    #+#             */
/*   Updated: 2024/11/30 14:52:58 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_objects(t_game *game, void *object, char *path, char c)
{
	int		img_width;
	int		img_height;
	int		i;
	int		j;

	i = 0;
	object = mlx_xpm_file_to_image(game->mlx_ptr, \
					path, &img_width, &img_height);
	while (i < game->win_height / 32)
	{
		j = 0;
		while (j < game->win_width / 32)
		{
			if (game->map[i][j] == c)
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
						object, (j * 32), (i * 32));
			}
			j++;
		}
		i++;
	}
}

void	render_game(t_game *game)
{
	render_objects(game, game->object, "./assets/wall.xpm", '1');
	render_objects(game, game->object, "./assets/link.xpm", 'P');
	render_objects(game, game->object, "./assets/triforce.xpm", 'E');
	render_objects(game, game->object, "./assets/ground.xpm", '0');
	render_objects(game, game->object, "./assets/rupee.xpm", 'C');
	mlx_hook(game->mlx_win, 17, 1L << 2, exit_game, game);
}
