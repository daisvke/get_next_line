/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:30:09 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/22 02:21:47 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_alloc(char **line)
{
	char	*s;
	char	*p;

	s = (char *)malloc(sizeof(*s));
	if (!s)
		return (ERROR);
	p = s;
	*p = '\0';
	*line = s;
	return (0);
}

int	ft_join(char **line, char **s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*tmp_s1;
	char	*tmp_s2;
	char	*str;

	tmp_s1 = *s1;
	tmp_s2 = s2;
	str = (char *)malloc(sizeof(*str) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
	if (!str)
		return (ERROR);
	i = 0;
	j = 0;
	while (tmp_s1[i])
		str[j++] = tmp_s1[i++];
	i = 0;
	while (tmp_s2[i])
		str[j++] = tmp_s2[i++];
	str[j] = '\0';
	*line = str;
	free(tmp_s1);
	return (0);
}

int	ft_get_prev(char **prev, int *pos, char **line)
{
	char	*tmp;

	*pos = ft_strchr(*prev, '\n');
	if (*pos >= 0)
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
	if (!*line)
		return (ERROR);
	free(*prev);
	*prev = 0;
	return (0);
}

int	ft_set_line(char **line, char **prev, char *buf, int r)
{
	char	*tmp;
	int		pos;

	buf[r] = 0;
	pos = ft_strchr(buf, '\n');
	if (pos >= 0)
	{
		tmp = ft_strsdup(buf, pos);
		if (!tmp || ft_join(line, line, tmp) == ERROR)
			return (ERROR);
		free(tmp);
		if (pos < r - 1)
		{
			*prev = ft_strsdup(&buf[pos + 1], r - pos - 1);
			if (!*prev)
				return (ERROR);
		}
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	static char	*prev;
	int			r;
	int			pos;

	if (BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0 || !line || ft_alloc(line) < 0)
		return (ERROR);
	if (prev)
		if (ft_get_prev(&prev, &pos, line))
			return (READ_LINE);
	while (1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0 || !*line)
			return (ERROR);
		if (!r)
			return (REACHED_EOF);
		r = ft_set_line(line, &prev, buf, r);
		if (r == ERROR)
			return (ERROR);
		if (r)
			return (READ_LINE);
		ft_join(line, line, buf);
	}
}
