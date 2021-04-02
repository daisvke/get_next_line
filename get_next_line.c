/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:30:09 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/02 02:26:03 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	int			r;
	char		buf[BUFFER_SIZE + 1];
	static char	*prev;
	char		*tmp;
	long		pos;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	*line = calloc(1, sizeof(*line));
	tmp = ft_calloc(1, sizeof(tmp));
	if (!tmp)
		return (-1);
	if (prev)
	{
		if (prev && (pos = ft_strchr(prev, '\n')) >= 0)
		{
			*line = ft_strsdup(prev, pos);
			prev = ft_substr(prev, pos + 1, ft_strlen(prev) - pos);
			free(tmp);
			return (1);
		}
		*line = ft_strdup(prev);
		prev = 0;
	}
	ft_bzero(buf, sizeof(buf));
	while ((r = read(fd, buf, BUFFER_SIZE)))
	{
		if (r < 0)
		{
			if (tmp)
				free(tmp);
			return (-1);
		}
		pos = ft_strchr(buf, '\n');
		if (pos >= 0)
		{
			*line = ft_strjoin(*line, ft_strsdup(buf, pos));
			free(tmp);
			if (pos < BUFFER_SIZE - 1)
			{
				prev = 0;
				prev = ft_strsdup(&buf[pos + 1], BUFFER_SIZE - (pos + 1));
			}
			return (1);
		}
		else
			*line = ft_strjoin(*line, buf);
		ft_bzero(buf, sizeof(buf));
	}
	return (0);
}

#include <stdio.h>
/*
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

	fd = open("t", O_RDONLY);
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


if \n || EOF(= read = 0) in buf
	return before symb
else if read < 0
	return -1

else 
	cpy buf in allocated (return -1 if fails) char *exbuf
	read new bufsize
	if \n || EOF
		if \n only
			return empty string
		concat exbuf + buf into line
		return 1 (\n) || 0 (EOF)

	(bufsize can store max = one line (until EOF)
	so if exbuf allocation len is buf len = ok)
*/
