/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:07:23 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/09/21 05:08:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join(t_gnl *data, char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2);
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

int gnl_set_line(t_gnl *fd_data, char **line, int fd)
{
    size_t 	 pos;
	char	*tmp;
    int		ret;
	bool	is_null;
    
	while (true)
	{
		ret = read(fd, fd_data->buffer, BUFFER_SIZE);
        if (ret < 0)
            return (ERROR);
        if (ret == 0)
			break ;
        fd_data->buffer[ret] = '\0';
		tmp = ft_join(fd_data, fd_data->content, fd_data->buffer);
        if (fd_data->error == true)
            return (ERROR);
		free(fd_data->content);
		fd_data->content = tmp;
		if (ft_strchr(fd_data->buffer, '\n') > NOT_FOUND)
			break ;
	}
    pos = 0;
	if (fd_data->content) 
		while (fd_data->content[pos] && fd_data->content[pos] != '\n')
			pos++;
	is_null = pos + 1 > ft_strlen(fd_data->content);
	*line = ft_substr(fd_data, fd_data->content, pos, 0);
	tmp = ft_substr(fd_data, fd_data->content + pos + 1, ft_strlen(fd_data->content) - pos - 1, is_null);
	free(fd_data->content);
	fd_data->content = tmp;
	if (ret == REACHED_EOF && is_null)
		return (REACHED_EOF);
	else
	    return (LINE_READ);
}

int	get_next_line(int fd, char **line)
{
    static t_gnl   *data;
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
    return (gnl_set_line(fd_data, line, fd));
}
