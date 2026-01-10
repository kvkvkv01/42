/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wagyu <wagyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2026/01/07 12:00:00 by wagyu             #+#    #+#             */
/*   Updated: 2026/01/07 12:00:00 by wagyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_chain
{
	char			*buf;
	struct s_chain	*next;
}	t_chain;

typedef struct s_list
{
	int				fd;
	char			*stash;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_add_chain(t_chain **lst, t_chain **tail, char *buf);
char	*ft_flatten(char *stash, t_chain *lst);
t_list	*get_node(t_list **head, int fd);

#endif
