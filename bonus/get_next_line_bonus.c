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
char	*ft_join(t_data *data, char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
    {
        data->error = true;
		return (NULL);
    }
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
    return (str);
}
/*
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
*/

int gnl_set_line(t_data *data, char *buffer, char **line)
{
    int  pos;
    
    pos = 0;
    while (buffer[pos] && buffer[pos] != '\n')
        pos++;
   
    if (buffer[pos] == '\0')
    {
       *line = ft_strdup(data, buffer);
     //  ft_bzero(buffer, BUFFER_SIZE);
        free(buffer);
    }
    else
    {
        *line = ft_substr(buffer, 0, pos);
        free(buffer);
        buffer = ft_substr(buffer, pos + 1, BUFFER_SIZE - pos + 1);
    }
    
    return (LINE_READ);
}

t_data   *gnl_get_data(t_data *data, int fd)
{
    t_data *head;

    head = data;
    while (head)
    {
        if (head->fd == fd)
            return (head);
        head = head->next;
    }
    head = malloc(sizeof(*head));
    if (!head)
        data->error = true;
    head->fd = fd;
  //  ft_bzero(head->buffer, BUFFER_SIZE);
    head->buffer = NULL;
    head->next = NULL;
    return (head);
}

int	get_next_line(int fd, char **line)
{
    static t_data   *data;
    char            **buffer_fd;
    char            buffer[BUFFER_SIZE + 1];
    int             res;
    char            *tmp;

    data = gnl_get_data(data,fd);
    buffer_fd = &data->buffer;
    printf("got: %s, fd: %d\n", *buffer_fd, data->fd);
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (ERROR);
    ft_bzero(buffer, BUFFER_SIZE);
	while (true) 
	{
		res = read(fd, buffer, BUFFER_SIZE);
        buffer[res] = '\0';
        if (res < 0)
            return (ERROR);
        if (res == 0)
            return (EOF);
        if (*buffer_fd == NULL)
        {
            *buffer_fd = ft_strdup(data, buffer);
       //     printf("null, buf: %si  ", buffer_fd);
    printf("gotnew: %s  ", data->buffer);
        }
        else
        {
            printf("notnull");

            tmp = ft_join(data, *buffer_fd, buffer);
            free(buffer_fd);
            *buffer_fd = tmp;
           // ft_bzero(buffer, ft_strlen(buffer));
        }
         //   return (LINE_READ);
        if (data->error == true)
            return (ERROR);
        if (ft_strchr(buffer, '\n'))
            break ;
	}
 //   printf("buf: %c", buffer_fd[0]);
    gnl_set_line(data, *buffer_fd, line);
    
   //*line = ft_strdup(&data, "epictete");	
	return (REACHED_EOF);
}
