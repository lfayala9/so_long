/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:21:11 by layala-s          #+#    #+#             */
/*   Updated: 2024/11/12 13:21:14 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_extension(char *filename, char *extension)
{
	int	len_file;
	int	len_ext;

	len_ext = ft_strlen(extension);
	len_file = ft_strlen(filename);
	if (len_file <= len_ext)
		return (0);
	if (ft_strncmp(filename + len_file - len_ext, extension, len_ext) == 0)
		return (1);
	return (0);
}

void	check_map(int fd, char *line, int width)
{
	char	*buffer;
	int		cur_len;

	buffer = line;
	cur_len = ft_strlen(buffer);
	if (buffer[cur_len - 1] == '\n')
		cur_len--;
	if (cur_len != width)
	{
		free(buffer);
		exit_error("Error: Invalid map dimensions!");
	}
	buffer = line;
}
void	assign_map_pos(int i, int width, int height, char *buffer, t_game *window)
{
	while (i < width)
	{
		if (buffer[i] == 'P')
		{
			window->pos_x = i;
			window->pos_y = height;
		}
		if (buffer[i] == 'E')
		{
			window->e_pos_x = i;
			window->e_pos_y = height;
		}
		i++;
	}
}

void	assign_map_val(int height, int width, int fd, char *buffer, t_game *window)
{
	int i;

	i = 0;
	while (buffer)
	{
		i = 0;
		assign_map_pos(i, width, height, buffer, window);
		check_map(fd, buffer, width);
		window->map = ft_realloc(window->map, sizeof(char *) * (height + 1));
		if (!window->map)
			exit_error("Error: Map allocation failed!");
		window->map[height] = buffer;
		buffer = get_next_line(fd);
		height++;
	}
	window->map[height] = NULL;
	window->win_height = height;
	window->win_width = width;
	close(fd);
}

void	get_map(char *filename, t_game *window)
{
	int		width;
	int		height;
	int		fd;
	char	*buffer;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("Error: File not found!");
	height = 0;
	buffer = get_next_line(fd);
	if (!buffer)
		exit_error("Error: Empty file!");
	width = ft_strlen(buffer) - 1;
	window->map = malloc(sizeof(char *) * 1);
	if (!window->map)
		exit_error("Error: Map allocation failed!");
	assign_map_val(height, width, fd, buffer, window);
}
