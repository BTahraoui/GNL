/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batahrao <batahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 06:44:58 by batahrao          #+#    #+#             */
/*   Updated: 2026/11/17 07:09:52 by batahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stashbox(char *stash)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*saved;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	len = ft_strlen(stash);
	saved = malloc((len - i) * sizeof(char));
	if (!saved)
		return (free(stash), NULL);
	i++;
	while (stash[i])
	{
		saved[j] = stash[i];
		j++;
		i++;
	}
	saved[j] = '\0';
	return (free(stash), saved);
}

char	*to_get(char *stash)
{
	int		i;
	char	*ptr;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 2)); //+ 2 for '\n' and '\0'
	if (!ptr)
		return (NULL);
	ptr[i + 1] = '\0';
	while (i >= 0)
	{
		ptr[i] = stash[i];
		i--;
	}
	return (ptr);
}

char	*to_read(int fd, char *stash)
{
	int		read_bytes;
	char	*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (ft_strchr(stash, '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == 0 && *stash)
			break ;
		else if (read_bytes <= 0)
			return (free(buff), free(stash), NULL);
		buff[read_bytes] = '\0';
		{
			char	*joined;

			joined = ft_strjoin(stash, buff);
			if (!joined)
				return (free(buff), free(stash), NULL);
			free(stash);
			stash = joined;
		}
	}
	return (free(buff), stash);
}

char	*get_next_line(int fd)
{
	static char *stash;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if(!stash)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);
	stash = to_read(fd, stash);
	if (!stash)
		return (NULL);
	line = to_get(stash);
	if (!line)
		return (free(stash), NULL);
	stash = ft_stashbox (stash);
	return (line);
}