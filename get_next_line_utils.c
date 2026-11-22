/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batahrao <batahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 11:18:59 by batahrao          #+#    #+#             */
/*   Updated: 2026/11/22 11:14:58 by batahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *d, char *s)
{
	int	i;

	i = 0;
	if (!d || !s)
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

int	ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	x;

	if (!s)
		return (-1);
	i = 0;
	x = (unsigned char)c;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == x)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_join(char *d, char *s)
{
	size_t	d_len;
	size_t	s_len;
	char	*joined;

	d_len = ft_strlen(d);
	s_len = ft_strlen(s);
	joined = malloc(d_len + s_len + 1);
	if (!joined)
		return (NULL);
	ft_strcpy(joined, d);
	ft_strcpy(joined + d_len, s);
	return (joined);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	dup = malloc(s_len + 1);
	if (!dup)
		return (NULL);
	ft_strcpy(dup, (char *)s);
	return (dup);
}
