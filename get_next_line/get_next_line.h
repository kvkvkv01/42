/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wagyu <wagyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2026/01/07 12:00:00 by wagyu             #+#    #+#             */
/*   Updated: 2026/01/07 12:00:00 by wagyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strjoin_free(char *s1, char *s2);
char *ft_substr(char *s, unsigned int start, size_t len);

#endif
