/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:30:09 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/04 03:16:42 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_alloc(int n)
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

void	ft_join(char **res, char **s1, char *s2)
{
	int		len;
	char	*tmp_s1;
	char	*tmp_s2;
	char	*joined;

	tmp_s1 = *s1;
	tmp_s2 = s2;
	len = ft_strlen(*s1) + ft_strlen(s2);
	joined = malloc(sizeof(*joined) * (len + 1));
	if (!joined)
		return ;
	ft_memcpy(joined, tmp_s1, ft_strlen(*s1));
	ft_memcpy(&joined[ft_strlen(*s1)], tmp_s2, ft_strlen(s2));
	joined[len] = 0;
	*res = joined;
	free(tmp_s1);
}

int		ft_get_prev(char **prev, int *pos, char **line)
{
	char	*tmp;

	if ((*pos = ft_strchr(*prev, '\n')) >= 0)
	{
		free(*line);
		*line = ft_strsdup(*prev, *pos);
		tmp = ft_strsdup(*prev, ft_strlen(*prev));
		free(*prev);
		*prev = ft_substr(tmp, *pos + 1, ft_strlen(tmp) - *pos);
		free(tmp);
		return (1);
	}
	free(*line);
	*line = ft_strsdup(*prev, ft_strlen(*prev));
	free(*prev);
	*prev = 0;
	return (0);
}

int		ft_set_line(char **line, char **prev, char *buf, int r)
{
	char	*tmp;
	int		pos;

	pos = ft_strchr(buf, '\n');
	if (pos >= 0)
	{
		ft_join(line, line, tmp = ft_strsdup(buf, pos));
		free(tmp);
		if (pos < r - 1)
			*prev = ft_strsdup(&buf[pos + 1], r - pos - 1);
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	static char	*prev;
	int			r;
	int			pos;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	*line = ft_alloc(0);
	if (*line && prev)
		if (ft_get_prev(&prev, &pos, line))
			return (1);
	while ((r = read(fd, buf, BUFFER_SIZE)))
	{
		if (r < 0 || !*line)
			return (-1);
		buf[r] = 0;
		if (ft_set_line(line, &prev, buf, r))
			return (1);
		ft_join(line, line, buf);
	}
	return (0);
}
