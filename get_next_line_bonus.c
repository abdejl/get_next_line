
#include "get_next_line_bonus.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif
char	*get_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (ft_substr(str, 0, i + 1));
}

char	*get_rest(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i] != '\n')
		i++;
	ptr = ft_substr(str, i + 1, ft_strlen(str) - i);
	free(str);
	return (ptr);
}

int	newline(char *str)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			k;
	char		*ln;
	static char	*rs[1024];
	char		*bf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!bf)
		return (NULL);
	if (newline(rs[fd]))
		return (ln = get_line(rs[fd]), rs[fd] = get_rest(rs[fd]), free(bf), ln);
	k = read(fd, bf, BUFFER_SIZE);
	if (k <= 0)
	{
		if (!rs[fd])
			return (free(bf), NULL);
		if (!*rs[fd])
			return (free(rs[fd]), free(bf), rs[fd] = NULL, NULL);
		ln = ft_strdup(rs[fd]);
		return (free(rs[fd]), free(bf), rs[fd] = NULL, ln);
	}
	bf[k] = '\0';
	return (rs[fd] = ft_strjoin(rs[fd], bf), free(bf), get_next_line(fd));
}