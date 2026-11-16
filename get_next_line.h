/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batahrao <batahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 06:36:07 by batahrao          #+#    #+#             */
/*   Updated: 2026/11/16 06:40:40 by batahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H


#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);

size_t	ft_strlen(const char *s);
size_t	ft_strchr(const char *s, int c);

void	*ft_memcpy(void *dest, const void *src, size_t n);

ssize_t read(int fd, void *buf, size_t count);




#endif