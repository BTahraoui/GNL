/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batahrao <batahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 06:44:58 by batahrao          #+#    #+#             */
/*   Updated: 2026/11/16 08:16:26 by batahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stashbox(char *stash)
{
	int		i;
	int		j;
	char	*saved;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	saved = malloc((ft_strlen(stash) - i) * sizeof(char));
	if (!saved)
		return (free(stash), NULL);
	while (stash[i])
	{
		saved[j] = saved[i + 1];
		j++;
		i++;
	}
	return (free(stash), saved);
}

