/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:07:31 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/09/21 06:00:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i])
			++i;
	return (i);
}

int	gnl_get_newline_pos(char *str, bool increment)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		++i;
	}
	if (increment)
		return (i);
	else
		return (NOT_FOUND);
}

char	*gnl_substr(t_gnl *data, char *str, size_t len, int is_empty)
{
	char	*ptr;
	size_t	i;
	size_t	size;

	size = 0;
	i = 0;
	while (str && is_empty == false && str[i++] && len--)
		++size;
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
	{
		data->error = true;
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		ptr[i] = str[i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}
