/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:30:09 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/03 03:57:16 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	int			r;
	static char	buf[BUFFER_SIZE + 1];
	static char	*prev;
	char		*tmp;
	char		*tmp2;
	long		pos;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	*line = ft_alloc(0);
	if (!*line)
		return (-1);
	if (prev)
	{
		if ((pos = ft_strchr(prev, '\n')) >= 0)
		{
			free(*line);
			*line = ft_strsdup(prev, pos);
			tmp = ft_strsdup(prev, ft_strlen(prev));
			free(prev);
			prev = ft_substr(tmp, pos + 1, ft_strlen(tmp) - pos);
			free(tmp);
			tmp = 0;
			return (1);
		}
		free(*line);
		*line = ft_strsdup(prev, ft_strlen(prev));
		free(prev);
		prev = 0;
	}
	while ((r = read(fd, buf, BUFFER_SIZE)))
	{
		if (r < 0)
			return (-1);
		buf[r] = 0;
		pos = ft_strchr(buf, '\n');
		if (pos >= 0)
		{	
			tmp = ft_strsdup(buf, pos);
			tmp2 = *line;
			*line = ft_strjoin(tmp2, tmp);
			free(tmp2);
			tmp2 = 0;
			free(tmp);
			tmp = 0;
			if (pos < r - 1)
				prev = ft_strsdup(&buf[pos + 1], r - pos - 1);
			return (1);
		}
		else
		{
			tmp = *line;
			*line = ft_strjoin(tmp, buf);
			free(tmp);
			tmp = 0;
		}
	}
	return (0);
}

/*
int	main()
{
	int		fd;
	char	*line;
	int		ret;

	fd = open("t3", O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("1ret: %d\n", ret);
	printf("1line: |%s|\n", line);
	ret = get_next_line(fd, &line);
	printf("2ret: %d\n", ret);
	printf("2line: %s\n", line);
	ret = get_next_line(fd, &line);
	printf("3ret: %d\n", ret);
	printf("3line: %s\n", line);
	ret = get_next_line(fd, &line);
	printf("4ret: %d\n", ret);
	printf("4line: %s\n", line);
	ret = get_next_line(fd, &line);
	printf("5ret: %d\n", ret);
	printf("5line: %s\n", line);
	close(fd);
	
	printf("\n\n\n");

	fd = open("t2", O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("1ret: %d\n", ret);
	printf("1line: %s\n", line);
	ret = get_next_line(fd, &line);
	printf("2ret: %d\n", ret);
	printf("2line: %s\n", line);
	ret = get_next_line(fd, &line);
	printf("3ret: %d\n", ret);
	printf("3line: %s\n", line);
	ret = get_next_line(fd, &line);
	printf("3ret: %d\n", ret);
	printf("3line: %s\n", line);
	close(fd);
	free(line);
}

*/
