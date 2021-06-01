/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:07:31 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/23 06:27:16 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(char *s, size_t n)
{
	while (*s && n--)
		*s++ = '\0';
}

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

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	size;

	size = 0;
	i = start;
	while (s[i++] && len--)
		size++;
	p = ft_strsdup((char *)&s[start], size, NULL, 0);
	if (!p)
		return (NULL);
	return (p);
}
