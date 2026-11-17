/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batahrao <batahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 06:38:15 by batahrao          #+#    #+#             */
/*   Updated: 2026/11/17 07:13:48 by batahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*to_join;
	size_t	total;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total = s1_len + s2_len;
	to_join = malloc((total + 1) * sizeof(char));
	if (!to_join)
		return (NULL);
	ft_memcpy(to_join, s1, s1_len);
	ft_memcpy(to_join + s1_len, s2, s2_len);
	to_join[total] = '\0';
	return (to_join);
}

char	*ft_strdup(const char *s1)
{
	char	*to_dup;
	size_t	total;
	size_t	i;

	if (!s1)
		return (NULL);
	total = ft_strlen(s1);
	to_dup = malloc((total + 1) * sizeof(char));
	if (!to_dup)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		to_dup[i] = s1[i];
		i++;
	}
	to_dup[i] = '\0';
	return (to_dup);
}

size_t	ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (char)c)
			return (0);
		i++;
	}
	return (1);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
