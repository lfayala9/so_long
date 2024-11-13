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

int	get_width(int fd)
{
	int len;
	char buffer[1024];
	int bytesRead;

	len = 0;
	if (fd < 0)
		exit(EXIT_FAILURE);
	bytesRead = read(fd, buffer, sizeof(buffer));
	if (bytesRead <= 0)
		exit(EXIT_FAILURE);
	buffer[bytesRead] = '\0';
	while (buffer[len] != '\n')
			len++;
	return (len);
}
