/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:30:23 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/04 02:44:40 by dtanigaw         ###   ########.fr       */
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

char	*ft_alloc(int n);
void	ft_join(char **res, char **s1, char *s2);
void	ft_memcpy(char *dest, char *src, size_t n);
int		ft_strchr(char *s, int c);
int		ft_strlen(char *s);
char	*ft_strsdup(char *src, int size);
char	*ft_substr(char *s, int start, int len);
int		get_next_line(int fd, char **line);
int		ft_get_prev(char **prev, int *pos, char **line);

#endif
