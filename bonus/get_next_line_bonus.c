/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:07:23 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/09/21 06:18:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_concatenate(t_gnl *data, char *s1, char *s2)
{
	size_t	size;
	char	*str;
	size_t	i;
	size_t	j;

	size = gnl_strlen(s1) + gnl_strlen(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
	{
		data->error = true;
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1 && s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

int	gnl_set_line(t_gnl *fd_data, int fd)
{
	int		ret;
	char	*tmp;

	while (gnl_get_newline_pos(fd_data->content, false) == NOT_FOUND)
	{
		ret = read(fd, fd_data->buffer, BUFFER_SIZE);
		if (ret < 0)
			return (ERROR);
		if (ret == 0)
			break ;
		fd_data->buffer[ret] = '\0';
		tmp = gnl_concatenate(fd_data, fd_data->content, fd_data->buffer);
		if (fd_data->error == true)
			return (ERROR);
		free(fd_data->content);
		fd_data->content = tmp;
	}
	return (ret);
}

int	gnl_execute_and_return(t_gnl *fd_data, char **line, int fd)
{
	int		ret;
	size_t	pos;
	char	*tmp;
	bool	is_empty;

	ret = gnl_set_line(fd_data, fd);
	if (ret == ERROR)
		return (ERROR);
	if (fd_data->content)
		pos = gnl_get_newline_pos(fd_data->content, true);
	is_empty = pos + 1 > gnl_strlen(fd_data->content);
	*line = gnl_substr(fd_data, fd_data->content, pos, 0);
	if (fd_data->error == true)
		return (ERROR);
	tmp = gnl_substr(fd_data, fd_data->content + pos + 1, \
		gnl_strlen(fd_data->content) - pos - 1, is_empty);
	if (fd_data->error == true)
		return (ERROR);
	free(fd_data->content);
	fd_data->content = tmp;
	if (ret == REACHED_EOF && is_empty)
		return (REACHED_EOF);
	else
		return (LINE_READ);
}

int	get_next_line(int fd, char **line)
{
	static t_gnl	*data;
	t_gnl			*fd_data;

	if (BUFFER_SIZE <= 0 || !line)
		return (ERROR);
	fd_data = data;
	while (fd_data && fd_data->fd != fd)
	{
		fd_data = fd_data->next;
	}
	if (!fd_data)
	{
		fd_data = malloc(sizeof(t_gnl));
		if (!fd_data)
			fd_data->error = true;
		fd_data->fd = fd;
		fd_data->content = NULL;
		fd_data->error = false;
		fd_data->next = data;
		data = fd_data;
	}
	return (gnl_execute_and_return(fd_data, line, fd));
}
