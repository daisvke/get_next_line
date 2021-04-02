/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:30:23 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/01 19:04:44 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);
long	ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
long	ft_strlen(char *s);
char	*ft_strsdup(char *src, int size);
char	*ft_substr(char *s, long start, long len);
int		get_next_line(int fd, char **line);

#endif
