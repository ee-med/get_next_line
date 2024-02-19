/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hach <mel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:57:10 by mel-hach          #+#    #+#             */
/*   Updated: 2024/02/19 21:39:55 by mel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*check_and_alloc(char *buffer, int fd)
{
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > INT_MAX || read(fd, NULL, 0) < 0)
		return (free(buffer), buffer = NULL);
	if (!buffer)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static t_var	e;

	e.buffer[fd] = check_and_alloc(e.buffer[fd], fd);
	if (!e.buffer[fd])
		return (NULL);
	e.line = ft_strjoin(NULL, e.buffer[fd]);
	if (!e.line)
		return (free(e.buffer[fd]), e.buffer[fd] = NULL);
	store_remainder(e.buffer[fd]);
	if (check_str(e.line) >= 0)
		return (e.line);
	e.bytes_readed = 1;
	while (e.bytes_readed > 0)
	{
		e.bytes_readed = read(fd, e.buffer[fd], BUFFER_SIZE);
		if (e.bytes_readed == -1 || (e.bytes_readed == 0 && e.line[0] == '\0'))
			return (free(e.line), free(e.buffer[fd]), e.buffer[fd] = NULL);
		e.line = ft_strjoin(e.line, e.buffer[fd]);
		if (!e.line)
			return (free(e.buffer[fd]), e.buffer[fd] = NULL);
		store_remainder(e.buffer[fd]);
		if (check_str(e.line) >= 0)
			return (e.line);
	}
	return (e.line);
}
