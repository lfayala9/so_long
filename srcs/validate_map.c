/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:51:10 by layala-s          #+#    #+#             */
/*   Updated: 2024/11/18 04:51:15 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_error(char *error_type)
{
	ft_printf(error_type);
	exit(EXIT_FAILURE);
}

int	check_borders(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_exit(char **map, int pos_x, int pos_y, t_game *game)
{
	if (pos_x < 0 || pos_x >= game->win_height \
		|| pos_y < 0 || pos_y >= game->win_width \
		|| map[pos_x][pos_y] == '1')
		return (0);
	if (map[pos_x][pos_y] == 'E')
		return (1);
	map[pos_x][pos_y] = '1';
	if (check_exit(map, pos_x - 1, pos_y, game) || 
		check_exit(map, pos_x + 1, pos_y, game) ||
		check_exit(map, pos_x, pos_y - 1, game) ||
		check_exit(map, pos_x, pos_y + 1, game))
		return (1);
	return (0);
}


int	count_objects(char **map, int width, int height, t_game *game)
{
	int	i;
	int	j;


	i = 0;
	game->coins = 0;
	game->p_count = 0;
	game->e_count = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'P')
				game->p_count++;
			else if (map[i][j] == 'E')
				game->e_count++;
			else if (map[i][j] == 'C')
				game->coins++;
			j++;
		}
		i++;
	}
}

void	validate_map(t_game *game)
{
	if (!check_exit(game->map, game->pos_y, game->pos_x, game))
		exit_error("Error: Exit is not accessible!");
	if (game->e_count != 1)
		exit_error("Error: There should be only ONE exit!");
	if (game->p_count != 1)
		exit_error("Error: There should be only ONE player!");
	if (check_borders(game->map, game->win_width, game->win_height) == 0)
		exit_error("Error: The border character in the .ber file should be 1!");
}
