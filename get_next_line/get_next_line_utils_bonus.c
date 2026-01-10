/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wagyu <wagyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2026/01/07 12:00:00 by wagyu             #+#    #+#             */
/*   Updated: 2026/01/07 12:00:00 by wagyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_add_chain(t_chain **lst, t_chain **tail, char *buf)
{
	t_chain	*new_node;

	new_node = malloc(sizeof(t_chain));
	if (!new_node)
		return (0);
	new_node->buf = buf;
	new_node->next = NULL;
	if (!*lst)
		*lst = new_node;
	else
		(*tail)->next = new_node;
	*tail = new_node;
	return (1);
}

t_list	*get_node(t_list **head, int fd)
{
	t_list	*cur;

	cur = *head;
	while (cur)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	cur = malloc(sizeof(t_list));
	if (!cur)
		return (NULL);
	cur->fd = fd;
	cur->stash = NULL;
	cur->next = *head;
	*head = cur;
	return (cur);
}

static void	ft_copy_chain(char *str, t_chain *lst)
{
	t_chain	*tmp;
	size_t	i;
	size_t	j;

	i = ft_strlen(str);
	while (lst)
	{
		j = 0;
		while (lst->buf[j])
			str[i++] = lst->buf[j++];
		tmp = lst;
		lst = lst->next;
		free(tmp->buf);
		free(tmp);
	}
	str[i] = '\0';
}

char	*ft_flatten(char *stash, t_chain *lst)
{
	char	*str;
	t_chain	*tmp;
	size_t	len;
	size_t	i;

	len = ft_strlen(stash);
	tmp = lst;
	while (tmp)
	{
		len += ft_strlen(tmp->buf);
		tmp = tmp->next;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = -1;
	if (stash)
		while (stash[++i])
			str[i] = stash[i];
	else
		i = 0;
	str[i] = '\0';
	ft_copy_chain(str, lst);
	free(stash);
	return (str);
}
