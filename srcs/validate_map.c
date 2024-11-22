/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:51:10 by layala-s          #+#    #+#             */
/*   Updated: 2024/11/20 04:26:00 by layala-s         ###   ########.fr       */
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

void	flood_fill(int pos_x, int pos_y, t_game *game, int **visited)
{
	if (pos_x < 0 || pos_x >= game->win_height || \
		pos_y < 0 || pos_y >= game->win_width || \
		visited[pos_x][pos_y] || game->map[pos_x][pos_y] == '1')
		return ;
	visited[pos_x][pos_y] = 1;
	flood_fill(pos_x - 1, pos_y, game, visited);
	flood_fill(pos_x + 1, pos_y, game, visited);
	flood_fill(pos_x, pos_y - 1, game, visited);
	flood_fill(pos_x, pos_y + 1, game, visited);
}

void	count_objects(char **map, int width, int height, t_game *game)
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
			if (map[i][j] == 'E')
				game->e_count++;
			if (map[i][j] == 'C')
				game->coins++;
			j++;
		}
		i++;
	}
}

void	validate_map(t_game *game)
{
	if (!check_objects(game, 'E') || !check_objects(game, 'P'))
		exit_error("Error: Exit is not accessible!");
	if (!check_objects(game, 'C'))
		exit_error("Error: EVERY Coin should be accessible!");
	if (game->e_count != 1)
		exit_error("Error: There should be only ONE exit!");
	if (game->p_count != 1)
		exit_error("Error: There should be only ONE player!");
	if (check_borders(game->map, game->win_width, game->win_height) == 0)
		exit_error("Error: The border character in the .ber file should be 1!");
}
