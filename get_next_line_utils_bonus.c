#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*str;
	char	*p;

	i = 0;
	str = (char *)s1;
	p = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l_str;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	l_str = ft_strlen(s);
	if (len >= l_str)
		len = l_str;
	if (start > l_str)
		str = malloc(1);
	else
	{
		str = malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		if (start < l_str)
		{
			while (i < len)
				str[i++] = s[start++];
		}
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		p[j++] = s2[i++];
	}
	p[j] = '\0';
	free(s1);
	return (p);
}