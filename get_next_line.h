/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batahrao <batahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 06:36:07 by batahrao          #+#    #+#             */
/*   Updated: 2026/11/17 07:21:19 by batahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 0
#endif

#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
size_t	ft_strchr(const char *s, int c);

#endif