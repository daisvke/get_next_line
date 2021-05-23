/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:07:38 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/23 06:21:08 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define ERROR -1
# define ERROR2 -2
# define REACHED_EOF 0
# define LINE_READ 1

# include <stdlib.h>
# include <unistd.h>

void	ft_bzero(char *s, size_t n);
int		ft_strchr(char *s, char c);
size_t	ft_strlen(char *s);
char	*ft_strsdup(char *src, size_t size, int **err, int location);
char	*ft_substr(char *s, size_t start, size_t len);
int		get_next_line(int fd, char **line);

#endif
