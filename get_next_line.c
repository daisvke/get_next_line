/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:30:09 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/03/31 04:31:54 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>


int	ft_strlen2(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr2(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	size;

	if (!s || start >= ft_strlen(s))
		return (calloc(1, sizeof(char)));
	size = 0;
	i = start;
	while (s[i++] && len--)
		size++;
	p = ft_strsdup((char *)&s[start], size);
	if (!p)
		return (0);
	return (p);
}

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_strdup2(char *s)
{
	char	*cpy;
	int		i;
	int		len;

	len = ft_strlen(s);
	cpy = malloc(sizeof(*cpy) * (len + 1));
	if (!cpy)
		return (0);
	i = 0;
	while (i < len)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		len;
	char	*joined;

	if (!s1 || !s2)
		return (malloc(0));
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(sizeof(*joined) * (len + 1));
	if (!joined)
		return (0);
	ft_memcpy(joined, s1, ft_strlen(s1));
	ft_memcpy(&joined[ft_strlen(s1)], s2, ft_strlen(s2));
	joined[len] = 0;
	return (joined);
}

int		ft_memchr2(void *ptr, int c)
{
	int				i;
	unsigned char	*s;

	if (!c)
		return (0);
	s = (unsigned char *)ptr;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	int			r;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			pos;
	static char	*prev;

printf("=======%s=========\n", prev);
	if (fd < 0 || !line || BUFFER_SIZE <= 0) // error
	{
		if (prev)
			free(prev);
		return (-1);
	}
	tmp = calloc(1, sizeof(tmp));
	ft_bzero(*line, sizeof(*line));
	if (prev)
	{
		if ((pos = ft_memchr2(prev, '\n')) >= 0)
		{
			*line = ft_strsdup(prev, pos);
			prev = ft_substr(prev, pos + 1, ft_strlen2(prev) - pos);
			return (1);
		}
		tmp = ft_strdup2(prev);
	}
	while (1)
	{
		ft_bzero(buf, sizeof(buf));
		r = read(fd, buf, BUFFER_SIZE);
		if (r == 0) // eof
		{
			free(prev);
			return (0);
		}
		pos = ft_memchr2(buf, '\n');
		if (**line)
		{
			tmp = ft_strjoin2(tmp, *line);
		}
		if (pos >= 0)
		{
			*line = ft_strjoin2(tmp, ft_strsdup(buf, pos)); //free tmp, line
			free(tmp);
			if (pos < BUFFER_SIZE - 1)
			{
				prev = ft_strsdup(&buf[pos + 1], BUFFER_SIZE - (pos + 1));
			}
			else
				ft_bzero(prev, sizeof(prev));
			return (1);
		}
		else if (pos < 0)
		{
			tmp = ft_strjoin2(tmp, buf);//free tmp, line
		}
		//*line = ft_strjoin2(tmp, buf);
	}
}

#include <stdio.h>

int		main(void)
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
	printf("2ret: %d\n", ret);
	printf("2line: %s\n", line);
	close(fd);
}

/*
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
