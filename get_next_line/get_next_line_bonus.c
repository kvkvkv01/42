#include "get_next_line_bonus.h"

static t_fdnode	*find_node(t_fdnode **head, int fd)
{
	t_fdnode	*cur;

	cur = *head;
	while (cur)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	cur = (t_fdnode *)malloc(sizeof(t_fdnode));
	if (!cur)
		return (NULL);
	cur->fd = fd;
	cur->stash = NULL;
	cur->next = *head;
	*head = cur;
	return (cur);
}

static void	remove_node(t_fdnode **head, int fd)
{
	t_fdnode	*prev;
	t_fdnode	*cur;

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
			free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

static char	*read_into_stash(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes;

	while (!ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(stash), NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	i;
	size_t	j;
	char	*line;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
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
	char	*rest;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	rest = ft_substr(stash, i + 1, ft_strlen(stash) - i - 1);
	free(stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static t_fdnode	*head;
	t_fdnode		*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = find_node(&head, fd);
	if (!node)
		return (NULL);
	node->stash = read_into_stash(fd, node->stash);
	if (!node->stash)
		return (remove_node(&head, fd), NULL);
	line = extract_line(node->stash);
	node->stash = trim_stash(node->stash);
	if (!node->stash)
		remove_node(&head, fd);
	return (line);
}
