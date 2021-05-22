/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:30:23 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/22 05:32:46 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define ERROR -1
# define ERROR2 -2
# define REACHED_EOF 0
# define LINE_READ 1

# include <stdlib.h>
# include <unistd.h>

int		ft_bzero(char *s, size_t n);
int		ft_strchr(char *s, char c);
size_t	ft_strlen(char *s);
char	*ft_strsdup(char *src, size_t size);
char	*ft_substr(char *s, size_t start, size_t len);
int		get_next_line(int fd, char **line);

#endif
