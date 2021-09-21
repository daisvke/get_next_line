/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:07:31 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/09/21 06:14:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_get_char_pos(char *str, char c, bool increment)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	if (increment)
		return (i);
	else
		return (NOT_FOUND);
}

char	*gnl_substr(t_gnl *data, char *str, size_t size, int is_empty)
{
	char	*ptr;
	size_t	i;
//	size_t	size;

//	size = 0;
	i = 0;
//	while (str && is_empty == false && str[i++] && len--)
//		++size;
    if (is_empty)
        size = 0;
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
