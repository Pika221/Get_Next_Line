/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hialpagu <hialpagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:50:34 by hialpagu          #+#    #+#             */
/*   Updated: 2024/12/17 16:50:34 by hialpagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t len)
{
	while (len--)
		*((unsigned char *)(s++)) = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	arr = malloc(size * count);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, size * count);
	return (arr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	arr = malloc(sizeof(char) * len);
	if (arr == NULL)
		return (NULL);
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[i])
	{
		arr[i] = s2[j];
		j++;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
