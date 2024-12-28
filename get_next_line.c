/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hialpagu <hialpagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:25:18 by hialpagu          #+#    #+#             */
/*   Updated: 2024/12/28 22:46:16 by hialpagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	line = (char *)malloc((ft_strlen(buffer) - i) + 1);
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
	line = (char *)malloc(sizeof(char) * i + 2);
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

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
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
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (buffer)
	{
		line = ft_line(buffer, '\n');
		buffer = ft_left(buffer, '\n');
		return (line);
	}
	return (NULL);
}
