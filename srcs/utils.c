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
