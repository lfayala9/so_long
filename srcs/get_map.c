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

void	check_map(int fd, char *line, int width, t_game *win)
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
		exit_error("Error: Invalid map dimensions!", win);
	}
	buffer = line;
}

void	assign_map_pos(int i, char *buffer, t_game *win)
{
	while (i < win->win_width)
	{
		if (buffer[i] == 'P')
		{
			win->pos_y = win->win_height;
			win->pos_x = i;
		}
		if (buffer[i] == 'E')
		{
			win->e_pos_y = win->win_height;
			win->e_pos_x = i;
		}
		i++;
	}
}

void	assign_map_val(int fd, char *buffer, t_game *win, int len)
{
	while (buffer)
	{
		assign_map_pos(0, buffer, win);
		check_map(fd, buffer, win->win_width, win);
		win->map[win->win_height] = ft_strdup(buffer);
		if (!win->map[win->win_height])
		{
			free(buffer);
			free_map(win);
			close(fd);
			exit_error("Error: Duplication Failed!", win);
		}
		free(buffer);
		buffer = get_next_line(fd);
		win->win_height++;
	}
	win->map[win->win_height] = NULL;
	close(fd);
}

void	get_map(char *filename, t_game *window)
{
	int		fd;
	int		len;
	char	*buffer;

	len = get_line_count(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("Error: File not found!", window);
	window->win_height = 0;
	buffer = get_next_line(fd);
	if (!buffer)
	{
		exit_error("Error: Empty file!", window);
		close(fd);
	}
	window->map = malloc(sizeof(char *) * len);
	if (!window->map)
	{
		free(buffer);
		close(fd);
		exit_error("Error: Map allocation failed!", window);
	}
	window->win_width = (ft_strlen(buffer) - 1);
	assign_map_val(fd, buffer, window, len);
}
