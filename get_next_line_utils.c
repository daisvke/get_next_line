/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:30:20 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/03 22:35:52 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_memcpy(char *dest, char *src, size_t n)
{
	char	*d;
	char	*s;

	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
}

int		ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*joined;


	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(sizeof(*joined) * (len + 1));
	if (!joined)
		return (0);
	ft_memcpy(joined, s1, ft_strlen(s1));
	ft_memcpy(&joined[ft_strlen(s1)], s2, ft_strlen(s2));
	joined[len] = 0;
	return (joined);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strsdup(char *src, int size)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(*dest) * (size + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*p;
	int		i;
	int		size;

	if (!s || start >= ft_strlen(s))
		return (0);
	size = 0;
	i = start;
	while (s[i++] && len--)
		size++;
	p = ft_strsdup((char *)&s[start], size);
	if (!p)
		return (0);
	return (p);
}
