/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wagyu <wagyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2026/01/07 12:00:00 by wagyu             #+#    #+#             */
/*   Updated: 2026/01/07 12:00:00 by wagyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	read_into_stash(int fd, char **stash)
{
	char	*buffer;
	t_chain	*list;
	t_chain	*tail;
	ssize_t	bytes;

	list = NULL;
	tail = NULL;
	while (1)
	{
		buffer = malloc((size_t)BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(buffer);
			if (bytes == -1)
				return (ft_flatten(NULL, list), 0);
			break ;
		}
		buffer[bytes] = '\0';
		if (!ft_add_chain(&list, &tail, buffer))
			return (free(buffer), ft_flatten(NULL, list), 0);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	*stash = ft_flatten(*stash, list);
	return (1);
}

static void	remove_node(t_list **head, int fd)
{
	t_list	*prev;
	t_list	*cur;

	prev = NULL;
	cur = *head;
	while (cur)
	{
		if (cur->fd == fd)
		{
			if (prev)
				prev->next = cur->next;
			else
				*head = cur->next;
			free(cur->stash);
			free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

static char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;
	size_t	j;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*trim_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*rest;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	rest = malloc(ft_strlen(stash) - i + 1);
	if (!rest)
		return (free(stash), NULL);
	j = 0;
	i++;
	while (stash[i])
		rest[j++] = stash[i++];
	rest[j] = '\0';
	free(stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_node(&head, fd);
	if (!node)
		return (NULL);
	if (!node->stash || !ft_strchr(node->stash, '\n'))
	{
		if (!read_into_stash(fd, &node->stash))
		{
			remove_node(&head, fd);
			return (NULL);
		}
	}
	if (!node->stash)
	{
		remove_node(&head, fd);
		return (NULL);
	}
	line = extract_line(node->stash);
	if (!line)
	{
		remove_node(&head, fd);
		return (NULL);
	}
	node->stash = trim_stash(node->stash);
	return (line);
}
