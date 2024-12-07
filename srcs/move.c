/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:21:21 by layala-s          #+#    #+#             */
/*   Updated: 2024/12/06 18:21:23 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	finish_game(t_game *game, char pos, int dir, int move_did)
{
	if (game->map[game->p_pos_y][game->p_pos_x] == 'E' && game->is_collected)
	{
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		ft_printf("Congratulations! You've completed the game!\n");
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	if (game->map[game->p_pos_y][game->p_pos_x] == 'C')
	{
		game->map[game->p_pos_y][game->p_pos_x] = '0';
		game->coins--;
	}
	if (move_did)
		ft_printf("You moved: %d times!\n", ++game->steps);
}

void	do_move(t_game *game, char pos, int dir)
{
	int	move_did;

	move_did = 0;
	if (game->coins == 0)
		game->is_collected = 1;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->object->background, game->p_pos_x * 32, game->p_pos_y * 32);
	if (pos == 'y' && game->map[game->p_pos_y + 1 * dir][game->p_pos_x] != '1' \
	&& (game->is_collected || \
	game->map[game->p_pos_y + 1 * dir][game->p_pos_x] != 'E'))
	{
		game->p_pos_y = game->p_pos_y + 1 * dir;
		move_did = 1;
	}
	if (pos == 'x' && game->map[game->p_pos_y][game->p_pos_x + 1 * dir] != '1' \
	&& (game->is_collected || \
	game->map[game->p_pos_y][game->p_pos_x + 1 * dir] != 'E'))
	{
		game->p_pos_x = game->p_pos_x + 1 * dir;
		move_did = 1;
	}
	finish_game(game, pos, dir, move_did);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->object->player, game->p_pos_x * 32, game->p_pos_y * 32);
}

int	hooks(int key, t_game *game)
{
	if (key == ESC)
		exit_game(game);
	if (key == UP_ARROW || key == W_KEY)
		do_move(game, 'y', -1);
	if (key == DOWN_ARROW || key == S_KEY)
		do_move(game, 'y', 1);
	if (key == LEFT_ARROW || key == A_KEY)
		do_move(game, 'x', -1);
	if (key == RIGHT_ARROW || key == D_KEY)
		do_move(game, 'x', 1);
	return (0);
}
