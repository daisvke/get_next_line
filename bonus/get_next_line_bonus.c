/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:07:23 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/23 16:33:29 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
/*
int	ft_alloc(char **fd_buf, size_t n)
{
	char	*s;
	char	*p;

	++n;
	s = (char *)malloc(sizeof(*s) * n);
	if (!s)
		return (ERROR);
	p = s;
	while (n--)
		*p++ = '\0';
	*fd_buf = s;
	return (0);
}
*/
void	ft_join(char **line, char **s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*tmp_s1;
	char	*tmp_s2;
	char	*str;

	tmp_s1 = *s1;
	tmp_s2 = s2;
	str = malloc(sizeof(*str) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
	if (!str)
		*line = NULL;
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
}

int	ft_get_prev(char *buf, int *pos, char **line)
{
	int		i;
	char	*tmp;

	*pos = ft_strchr(buf, '\n');
	if (*pos >= 0)
	{
		free(*line);
		*line = ft_strsdup(buf, *pos, &pos, -2);
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
	*line = ft_strsdup(buf, ft_strlen(buf), &pos, -2);
	ft_bzero(buf, ft_strlen(buf));
	return (0);
}

int	ft_set_line(char **line, char *buf, int r, int *err)
{
	char	*tmp;
	int		i;

	i = ft_strchr(buf, '\n');
	if (i >= 0)
	{
		tmp = ft_strsdup(buf, i, &err, -1);
		ft_join(line, line, tmp);
		free(tmp);
		if (i < r - 1)
		{
			tmp = ft_strsdup(&buf[i + 1], r - i - 1, &err, -2);
			ft_bzero(buf, ft_strlen(buf));
			i = -1;
			while (tmp[++i])
				buf[i] = tmp[i];
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
	static char	buffer[1024][BUFFER_SIZE];

	if (fd < 0 || read(fd, buffer[fd], 0) < 0 || BUFFER_SIZE <= 0 || !line)
		return (ERROR);
	while (read(fd, buffer[fd], BUFFER_SIZE))
	{
		if (read(fd, buffer[fd], 0) < 0)
			return (ERROR);
        if (buffer[fd][ft_strlen(buffer[fd])] == '\n')
            return (LINE_READ);
		ft_join(line, line, buffer[fd]);
		ft_bzero(buffer[fd], ft_strlen(buffer[fd]));
	}
	return (REACHED_EOF);
}