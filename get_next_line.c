/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batahrao <batahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 11:05:35 by batahrao          #+#    #+#             */
/*   Updated: 2026/11/21 16:01:29 by batahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(char *s)
{
	if (!s)
		return (-1);
	return (ft_strchr(s, '\n'));
}

char	*cut_line(char *s)
{
	char	*cutted_line;
	int		x;
	int		i;

	if (!s || !s[0])
		return (NULL);
	x = ft_strchr(s, '\n');
	if (x == -1)
		x = ft_strlen(s) - 1;
	cutted_line = malloc(x + 2);
	if (!cutted_line)
		return (NULL);
	i = 0;
	while (i <= x)
	{
		cutted_line[i] = s[i];
		i++;
	}
	cutted_line[i] = '\0';
	return (cutted_line);
}

char	*get_rest(char *s)
{
	char	*rest_ln;
	size_t	size;
	int		i;
	int		x;

	if (!s)
		return (NULL);
	x = find_nl(s);
	if (x == -1 || x == ft_strlen(s) - 1)
		return (NULL);
	x++;
	size = ft_strlen(s) - x;
	rest_ln = malloc(size + 1);
	if (!rest_ln)
		return (NULL);
	i = 0;
	while (i < size)
	{
		rest_ln[i] = s[x + i];
		i++;
	}
	rest_ln[i] = '\0';
	return (rest_ln);
}

char *ft_join_free(char *stash, char *buff)
{
	char *new_stash;
	if (!stash)
		stash = ft_strdup("");
	new_stash  = ft_join(stash, buff);
	free(stash);
	return (new_stash);
}

char	*read_to_stash(int fd, char *stash)
{
	char	*buff;
	int		res;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(stash), NULL);
	res = 1;
	while (find_nl(stash) == -1 && res > 0)
	{
		res = read(fd, buff, BUFFER_SIZE);
		if (res < 0)
			return (free(buff), free(stash), NULL);
		buff[res] = '\0';
		stash = ft_join_free(stash, buff);
		if (!stash)
			return (free(buff), NULL);
	}
	free(buff);
	if (stash && !stash[0])
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char *stash;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	
}

int	main(void)
{
	char *s = "dsad";
	char *s2 = "hello";
	char *x = ft_join_free(s, s2);
	printf("%s", x);
	free(x);
	x = NULL;
	return (0);
}