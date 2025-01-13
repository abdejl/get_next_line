/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abjellal <abjellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:20:42 by abjellal          #+#    #+#             */
/*   Updated: 2024/12/26 10:45:03 by abjellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*ft_read(int fd, char *str)
{
	char	*tmp_buff;
	ssize_t	num_of_bytes;

	tmp_buff = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!tmp_buff)
		return (NULL);
	num_of_bytes = 1;
	while (!ft_strchr(str, '\n') && num_of_bytes > 0)
	{
		num_of_bytes = read(fd, tmp_buff, BUFFER_SIZE);
		if (num_of_bytes == -1)
		{
			free(tmp_buff);
			return (NULL);
		}
		tmp_buff[num_of_bytes] = '\0';
		str = ft_strjoin(str, tmp_buff);
	}
	free(tmp_buff);
	return (str);
}

char	*ft_remaining(char *str)
{
	int		i;
	int		j;
	char	*remaining;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	remaining = (char *)malloc((ft_strlen(str) - i + 1));
	if (!remaining)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		remaining[j++] = str[i++];
	remaining[j] = '\0';
	free(str);
	return (remaining);
}

char	*ft_new_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*data_read[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data_read[fd] = ft_read(fd, data_read[fd]);
	if (!data_read[fd])
		return (NULL);
	line = ft_new_line(data_read[fd]);
	data_read[fd] = ft_remaining(data_read[fd]);
	return (line);
}
