/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batahrao <batahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 10:33:01 by batahrao          #+#    #+#             */
/*   Updated: 2026/11/18 11:13:43 by batahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_size;
	char	*res;
	int		i;
	int		j;

	i = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (total_size + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[total_size] = 0;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	size_t i;
	unsigned char x;

	i = 0;
	x = (unsigned char)c;
	while (s[i])
	{
		if ((unsigned char)s[i] == x)
			return ((char *)&s[i]);
		i++;
	}
	if (x == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char    *ft_strdup(const char *s1)
{
    char *to_dup;
    size_t total;
    size_t i;

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