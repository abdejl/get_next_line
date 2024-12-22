/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abjellal <abjellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:02:15 by abjellal          #+#    #+#             */
/*   Updated: 2024/12/15 21:00:10 by abjellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
	char		*line;
	static char	*remain;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (newline(remain))
		return (line = get_line(remain), remain = get_rest(remain), free(buff), line);
	k = read(fd, buff, BUFFER_SIZE);
	if (k <= 0)
	{
		if (!remain)
			return (free(buff), NULL);
		if (!*remain)
			return (free(buff), free(remain), remain = NULL, NULL);
		line = ft_strdup(remain);
		return (free(remain), free(buff), remain = NULL, line);
	}
	buff[k] = '\0';
	return (remain = ft_strjoin(remain, buff), free(buff), get_next_line(fd));
}


// #include <stdio.h>
// int main()
// {
//     char *buff;
//     int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
//     if (fd < 0)
//         return (1);

//     while ((buff = get_next_line(fd)) != NULL)
//     {
//         printf("%s", buff);
//         free(buff);
//     }
//     close(fd);
// }

// int main()
// {
//     char str[] = "hellooo\njgflkjjhg\nskldjks\n1234";
//     printf("%s", ft_new_line(str));
//     printf("%s", ft_remaining(str));
// }


// int main()
// {
//     char *buff = NULL;
//     int fd = open("test.txt", O_RDONLY);
//     buff = ft_read(fd, buff);
//     printf("%s", buff);
//     free(buff);
//     close(fd);

//     return 0;
// }