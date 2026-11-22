/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batahrao <batahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 11:06:00 by batahrao          #+#    #+#             */
/*   Updated: 2026/11/22 10:43:15 by batahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

// haeders
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_join(char *d, char *s);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
#endif
