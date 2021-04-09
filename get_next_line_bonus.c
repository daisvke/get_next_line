/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:07:23 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/09 18:39:34 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
void	ft_bzero(char *s, size_t n)
{
	while (n--)
		*s++ = 0;
}

char	*ft_alloc(size_t n)
{
	char	*s;
	char	*p;

	n = n + 1;
	s = malloc(sizeof(*s) * n);
	if (!s)
		return (0);
	p = s;
	while (n--)
		*p++ = 0;
	return (s);
}

void    ft_join(char **res, char **s1, char *s2)
{
        size_t  i;
        size_t  j;
        char    *tmp_s1;
        char    *tmp_s2;
        char    *str;

        tmp_s1 = *s1;
        tmp_s2 = s2;
        str = malloc(sizeof(*str) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
        if (!str)
                return ;
        i = 0;
        j = 0;
        while (tmp_s1[i])
			str[j++] = tmp_s1[i++];
        i = 0;
        while (tmp_s2[i])
			str[j++] = tmp_s2[i++];
        str[j] = 0;
        *res = str;
        free(tmp_s1);
}

int	ft_get_prev(char *buf, int *pos, char **line)
{
	int		i;
	char	*tmp;

	*pos = ft_strchr(buf, '\n');
	if (*pos >= 0)
	{
		free(*line);
		*line = ft_strsdup(buf, *pos);
		tmp = ft_substr(buf, *pos + 1, ft_strlen(buf) - *pos);
		ft_bzero(buf, ft_strlen(buf));
		i = -1;
		if (tmp)
			while (tmp[++i])
				buf[i] = tmp[i];
		buf[ft_strlen(tmp)] = 0;
		free(tmp);
		return (1);
	}
	free(*line);
	*line = ft_strsdup(buf, ft_strlen(buf));
	ft_bzero(buf, ft_strlen(buf));
	return (0);
}

int	ft_set_line(char **line, char *buf, int r)
{
	char	*tmp;
	int		pos;

	pos = ft_strchr(buf, '\n');
	if (pos >= 0)
	{
		tmp = ft_strsdup(buf, pos);
		ft_join(line, line, tmp);
		free(tmp);
		if (pos < r - 1)
		{
			tmp = ft_strsdup(&buf[pos + 1], r - pos - 1);
			ft_bzero(buf, ft_strlen(buf));
			ft_memcpy(buf, tmp, ft_strlen(tmp));
			buf[ft_strlen(tmp)] = 0;
			free(tmp);
		}
		else
			ft_bzero(buf, ft_strlen(buf));
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buf[1024];
	int			r;
	int			pos;

	if (BUFFER_SIZE <= 0 || read(fd, buf[fd], 0) < 0 || !line)
		return (-1);
	if (!buf[fd])
	{
		buf[fd] = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
		ft_bzero(buf[fd], BUFFER_SIZE);
	}
	*line = ft_alloc(0);
	if (*buf[fd])
		if (ft_get_prev(buf[fd], &pos, line))
			return (1);
	while (1)
	{
		ft_bzero(buf[fd], ft_strlen(buf[fd]));
		r = read(fd, buf[fd], BUFFER_SIZE);
		if (r < 0 || !*line)
			return (ERROR);
		if (!r)
			return (REACHED_EOF);
		buf[fd][r] = 0;
		if (ft_set_line(line, buf[fd], r))
			return (READ_LINE);
		ft_join(line, line, buf[fd]);
	}
}
