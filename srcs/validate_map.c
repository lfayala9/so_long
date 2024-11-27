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

void	exit_error(char *error_type, t_game *game)
{
	if (game)
		free_map(game);
	ft_printf("%s\n", error_type);
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

int	check_value(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->win_height)
	{
		j = 0;
		while (j < game->win_width)
		{
			if (game->map[i][j] != 'P' && \
				game->map[i][j] != 'E' && \
				game->map[i][j] != '1' && \
				game->map[i][j] != '0' && \
				game->map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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
	if (game->e_count != 1)
		exit_error("Error: There should be only ONE exit!", game);
	if (game->p_count != 1)
		exit_error("Error: There should be only ONE player!", game);
	if (game->coins == 0)
		exit_error("Error: There should be at least ONE Coin", game);
	if (check_borders(game->map, game->win_width, game->win_height) == 0)
		exit_error("Error: Border character in the .ber should be 1!", game);
	if (!check_value(game))
		exit_error("Error: Invalid character in map", game);
	if (!check_objects(game, 'E') || !check_objects(game, 'P'))
		exit_error("Error: Exit is not accessible!", game);
	if (!check_objects(game, 'C'))
		exit_error("Error: EVERY Coin should be accessible!", game);
	game->win_height = game->win_height * 32;
	game->win_width = game->win_width * 32;
}
