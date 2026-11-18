/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batahrao <batahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 10:33:05 by batahrao          #+#    #+#             */
/*   Updated: 2026/11/18 14:09:57 by batahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *stach_box(char *str)
{
    char *what_wegonna_save;
    
}




char *get_next_line(int fd)
{
    static char *str;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!str)
        str = ft_strdup("");
    if (!str)
        return (NULL);
    
}