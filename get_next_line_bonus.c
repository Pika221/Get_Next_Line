/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hialpagu <hialpagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:42:56 by hialpagu          #+#    #+#             */
/*   Updated: 2024/12/31 10:38:29 by hialpagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_left(char *buffer, char c)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != c)
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = malloc((ft_strlen(buffer) - i) + 1);
	if (!line)
		return (NULL);
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer, char c)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != c)
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != c)
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == c)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *res)
{
	char	*buffer;
	int		i;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr(res, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(res);
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		res = ft_strjoin(res, buffer);
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (buffer[fd])
	{
		line = ft_line(buffer[fd], '\n');
		buffer[fd] = ft_left(buffer[fd], '\n');
		return (line);
	}
	return (NULL);
}
