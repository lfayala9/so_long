/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 07:27:24 by layala-s          #+#    #+#             */
/*   Updated: 2024/11/20 07:27:25 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_line_count(char *filename)
{
	char	*line;
	int		len;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	len = 0;
	while (line)
	{
		free(line);
		len++;
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}

void	free_map(t_game *win)
{
	int	i;

	i = 0;
	if (win->map)
	{
		while (i < win->win_height)
		{
			if (win->map[i])
				free(win->map[i]);
			i++;
		}
		free(win->map);
		win->map = NULL;
	}
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->object)
	{
		if (game->object->wall)
			mlx_destroy_image(game->mlx_ptr, game->object->wall);
		if (game->object->player)
			mlx_destroy_image(game->mlx_ptr, game->object->player);
		if (game->object->background)
			mlx_destroy_image(game->mlx_ptr, game->object->background);
		if (game->object->coin)
			mlx_destroy_image(game->mlx_ptr, game->object->coin);
		if (game->object->exit)
			mlx_destroy_image(game->mlx_ptr, game->object->exit);
		free(game->object);
	}
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	ft_printf("You left the game :( %d\n", game->coins);
	free_game(game);
	exit(EXIT_SUCCESS);
}
