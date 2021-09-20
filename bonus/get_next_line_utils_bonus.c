/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:07:31 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/09/20 16:58:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (ERROR);
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

char	*ft_strsdup(char *src, size_t size, int **err, int location)
{
	size_t	i;
	char	*dest;

	dest = malloc(sizeof(*dest) * (size + 1));
	if (!dest)
	{
		**err = location;
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(t_gnl *data, char *src)
{
	size_t	i;
	size_t	size;
	char	*dest;

	size = ft_strlen(src);
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
	{
        data->error = true;
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char *s, size_t start, size_t len, int null)
{
	char	*p;
	size_t	i;
	size_t	size;

	if (s == NULL || null == true)
		return (NULL);
	size = 0;
	i = start;
	while (s[i++] && len--)
		size++;
	p = ft_strsdup((char *)&s[start], size, NULL, 0);
	if (!p)
		return (NULL);
	return (p);
}
