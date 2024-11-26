/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:59:06 by layala-s          #+#    #+#             */
/*   Updated: 2024/05/22 16:59:09 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_file(int fd, char *buffer)
{
	char	*tmp_buff;
	int		rd_bytes;

	tmp_buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!tmp_buff)
		return (NULL);
	rd_bytes = 1;
	while (rd_bytes != 0)
	{
		rd_bytes = read(fd, tmp_buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(tmp_buff);
			free(buffer);
			return (NULL);
		}
		tmp_buff[rd_bytes] = '\0';
		buffer = gnl_ft_strjoin(buffer, tmp_buff);
		if (gnl_ft_strchr(tmp_buff, '\n'))
			break ;
	}
	free(tmp_buff);
	tmp_buff = NULL;
	return (buffer);
}

static char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] != '\n' && buffer[i] == '\0')
	{
		line = ft_calloc(i + 1, sizeof(char));
	}
	else
		line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*store_buffer(char *buffer)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	s = (char *)ft_calloc(sizeof(char), (ft_strlen(buffer) - i));
	if (!s)
	{
		free(s);
		return (NULL);
	}
	i++;
	c = 0;
	while (buffer[i])
		s[c++] = buffer[i++];
	s[c] = '\0';
	free(buffer);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = store_buffer(buffer);
	return (line);
}
