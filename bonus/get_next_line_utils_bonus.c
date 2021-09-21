/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:07:31 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/09/21 04:59:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (NOT_FOUND);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

char	*ft_substr(t_gnl *data, char *s, size_t len, int is_null)
{
	char	*p;
	size_t	i;
	size_t	size;

	size = 0;
	i = 0;
	while (s && is_null == false && s[i++] && len--)
		size++;
	p = malloc(sizeof(char) * (size + 1));
	if (!p)
	{
		data->error = true;
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		p[i] = s[i];
		++i;
	}
	p[i] = '\0';
	return (p);
}
