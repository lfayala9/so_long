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

void	free_matrix(int index, int **visited, t_game *game)
{
	index = 0;
	while (index < game->win_height)
	{
		free(visited[index]);
		index++;
	}
	free(visited);
	return ;
}

void	locate_target(t_game *game, int	*found_tar, int **visited, char target)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < game->win_height)
	{
		j = 0;
		while (j < game->win_width)
		{
			k = 0;
			if (game->map[i][j] == target)
			{
				if (!visited[i][j])
					free_matrix(k, visited, game);
				(*found_tar)++;
			}
			j++;
		}
		i++;
	}
	free_matrix(i, visited, game);
}

int	check_objects(t_game *game, char object)
{
	int	**visited;
	int	i;
	int	j;
	int	found_object;

	i = 0;
	found_object = 0;
	visited = malloc(game->win_height * sizeof(int *));
	while (i < game->win_height)
	{
		j = 0;
		visited[i] = malloc(game->win_width * sizeof(int));
		while (j < game->win_width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	flood_fill(game->pos_x, game->pos_y, game, visited);
	locate_target(game, &found_object, visited, object);
	return (found_object > 0);
}
