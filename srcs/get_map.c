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

int	check_map(int fd, char *filename)
{
	char	*buffer;
	int		len;
	int		cur_len;

	buffer = get_next_line(fd);
	if (!buffer)
		return (0);
	if (fd < 0)
		return (free(buffer), 0);
	len = ft_strlen(buffer);
	if (buffer[len - 1] == '\n')
		len--;
	while (buffer)
	{
		cur_len = ft_strlen(buffer);
		if (buffer[cur_len - 1] == '\n')
			cur_len--;
		if (cur_len != len)
			return (free(buffer) ,0);
		free(buffer);
		buffer = get_next_line(fd);
	}
	return (1);
}

void	set_dimensions(char *filename, t_game *window)
{
	int		width;
	int		height;
	int		fd;
	char	*buffer;

	fd = open(filename, O_RDONLY);
	if (!check_extension(filename, ".ber"))
		exit_error("Error: Only .ber extension accepted!");
	if (!check_map(fd, filename))
		exit_error("Error: Invalid map dimensions!");
	close(fd);
	fd = open(filename, O_RDONLY);
	width = 0;
	height = 0;
	buffer = get_next_line(fd);
	width = ft_strlen(buffer) - 1;
	while (buffer)
	{
		free(buffer);
		buffer = get_next_line(fd);
		height++;
	}
	window->win_height = height * 32;
	window->win_width = width * 32;
	close(fd);
}
