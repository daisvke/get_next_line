/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:07:38 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/09/21 06:20:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 	32
# endif

# define NOT_FOUND		0
# define ERROR 			-1
# define REACHED_EOF 	0
# define LINE_READ		1

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl
{
	int				fd;
	char			*content;
	char			buffer[BUFFER_SIZE + 1];
	struct s_gnl	*next;
	bool			error;
}					t_gnl;

int		get_next_line(int fd, char **line);
int		gnl_get_char_pos(char *str, char c, bool increment);
char	*gnl_substr(t_gnl *data, char *str, size_t size, int is_empty);

#endif
