/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:30:09 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/02 22:15:01 by dtanigaw         ###   ########.fr       */
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
		if (prev && (pos = ft_strchr(prev, '\n')) >= 0)
		{
			*line = ft_strsdup(prev, pos);
			prev = ft_substr(prev, pos + 1, ft_strlen(prev) - pos);
			return (1);
		}
		*line = ft_strdup(prev);
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
				prev = ft_strsdup(&buf[pos + 1], BUFFER_SIZE - (pos + 1));
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
#include <stdio.h>
int		main(void)
{

	int             fd;
	int             i;
	int             j;
	char    		*line = 0;
	char			*lineadress[66];

	j = 1;
	if (!(fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 66)
		printf("\nRight number of lines\n");
	else if (j != 66)
		printf("\nNot Good - Wrong Number Of Lines\n");
	while (--j > 0)
		free(lineadress[j - 1]);
	j = 1;
}


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
