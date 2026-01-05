#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_fdnode
{
	int				fd;
	char			*stash;
	struct s_fdnode	*next;
}	t_fdnode;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif
