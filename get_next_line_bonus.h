/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hialpagu <hialpagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:41:09 by hialpagu          #+#    #+#             */
/*   Updated: 2024/12/28 21:45:16 by hialpagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FDS
#  define MAX_FDS 4242
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_left(char *buffer, char c);
char	*ft_line(char *buffer, char c);
char	*ft_read(int fd, char *res);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif