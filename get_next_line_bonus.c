/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:30:09 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/06 20:13:15 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

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

void	ft_join(char **res, char **s1, char *s2)
{
	size_t	len;
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

int	ft_get_prev(char *buf, int *pos, char **line)
{
	char	*tmp;

	*pos = ft_strchr(buf, '\n');
	if (*pos >= 0)
	{
		free(*line);
		*line = ft_strsdup(buf, *pos);
		tmp = ft_substr(buf, *pos + 1, ft_strlen(buf) - *pos);
		ft_bzero(buf, ft_strlen(buf));
		ft_memcpy(buf, tmp, ft_strlen(tmp));
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
	static char	buf[BUFFER_SIZE + 1];
	int			r;
	int			pos;

	if (BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0 || !line)
		return (-1);
	*line = ft_alloc(0);
	if (!*line)
		return (-1);
	if (*buf)
		if (ft_get_prev(buf, &pos, line))
			return (1);
	while (1)
	{
		ft_bzero(buf, ft_strlen(buf));
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0 || !*line)
			return (-1);
		if (!r)
			return (0);
		buf[r] = 0;
		if (ft_set_line(line, buf, r))
			return (1);
		ft_join(line, line, buf);
	}
}

/*
int	main()
{
	int		fd;
	char	*line;
	int		ret;

	fd = open("t6", O_RDONLY);
	printf("----------------------------\n\n");
	ret = get_next_line(fd, &line);
	printf("1ret: %d\n", ret);
	printf("1line: %s\n", line);
	printf("----------------------------\n\n");
	ret = get_next_line(fd, &line);
	printf("2ret: %d\n", ret);
	printf("2line: %s\n", line);
	printf("----------------------------\n\n");
	ret = get_next_line(fd, &line);
	printf("3ret: %d\n", ret);
	printf("3line: %s\n", line);
	printf("----------------------------\n\n");
	ret = get_next_line(fd, &line);
	printf("4ret: %d\n", ret);
	printf("4line: %s\n", line);
	printf("----------------------------\n\n");
	ret = get_next_line(fd, &line);
	printf("5ret: %d\n", ret);
	printf("5line: %s\n", line);
	close(fd);
	free(line);
}*/
