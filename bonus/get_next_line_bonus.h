/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:07:38 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/09/21 04:57:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 	32
# endif

# define NOT_FOUND		-1
# define ERROR 			-1
# define ERROR2 		-2
# define REACHED_EOF 	0
# define LINE_READ		1

// DEL !!!
# include <stdio.h>


# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_gnl
{
    int     		fd;
	char     		*content;
	char			buffer[BUFFER_SIZE + 1];
    struct s_gnl	*next;
    bool    		error;
}           		t_gnl;

int		ft_strchr(char *s, char c);
size_t	ft_strlen(char *s);
char	*ft_substr(t_gnl *data, char *s, size_t len, int is_null);
int		get_next_line(int fd, char **line);

#endif
