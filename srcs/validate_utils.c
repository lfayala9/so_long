/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:23:51 by layala-s          #+#    #+#             */
/*   Updated: 2024/11/20 12:23:54 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_matrix(t_game *game, int **visited)
{
	int	i;

	i = 0;
	while (i < game->win_height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	flood_fill(int x, int y, t_game *game, int **visited)
{
	if (x < 0 || x >= game->win_height || y < 0 || y >= game->win_width || \
		visited[x][y] || game->map[x][y] == '1')
		return ;
	visited[x][y] = 1;
	flood_fill(x - 1, y, game, visited);
	flood_fill(x + 1, y, game, visited);
	flood_fill(x, y - 1, game, visited);
	flood_fill(x, y + 1, game, visited);
}

void	locate_target(t_game *game, int *found_tar, int **visited, char target)
{
	int	i;
	int	j;
	int	is_accessible;

	i = 0;
	is_accessible = 1;
	while (i < game->win_height)
	{
		j = 0;
		while (j < game->win_width)
		{
			if (game->map[i][j] == target)
			{
				if (!visited[i][j])
					is_accessible = 0;
				else
					(*found_tar)++;
			}
			j++;
		}
		i++;
	}
	if (!is_accessible)
		*found_tar = 0;
	free_matrix(game, visited);
}

int	check_objects(t_game *game, char object)
{
	int	**visited;
	int	i;
	int	j;
	int	found;

	i = 0;
	found = 0;
	visited = malloc(game->win_height * sizeof(int *));
	while (i < game->win_height)
	{
		visited[i] = malloc(game->win_width * sizeof(int));
		j = 0;
		while (j < game->win_width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	flood_fill(game->p_pos_x, game->p_pos_y, game, visited);
	locate_target(game, &found, visited, object);
	return (found > 0);
}
