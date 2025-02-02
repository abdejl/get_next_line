/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abjellal <abjellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:02:15 by abjellal          #+#    #+#             */
/*   Updated: 2025/01/21 15:22:23 by abjellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (*str == 0)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_remaining(char *str)
{
	char	*remaining;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), NULL);
	remaining = (char *)malloc(ft_strlen(str) - i + 1);
	if (!remaining)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
	{
		remaining[j] = str[i];
		i++;
		j++;
	}
	remaining[j] = '\0';
	return (free(str), remaining);
}

char	*ft_read(int fd, char *str)
{
	char	*tmp_buff;
	int		num_of_bytes;

	tmp_buff = malloc(((size_t)BUFFER_SIZE + 1));
	if (!tmp_buff)
		return (NULL);
	num_of_bytes = 1;
	while (!ft_strchr(str, '\n') && num_of_bytes != 0)
	{
		num_of_bytes = read(fd, tmp_buff, BUFFER_SIZE);
		if (num_of_bytes == -1)
			return (free(tmp_buff), free(str), NULL);
		tmp_buff[num_of_bytes] = '\0';
		str = ft_strjoin(str, tmp_buff);
	}
	return (free(tmp_buff), str);
}

char	*get_next_line(int fd)
{
	static char	*data_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data_read = ft_read(fd, data_read);
	if (!data_read)
		return (NULL);
	line = ft_new_line(data_read);
	data_read = ft_remaining(data_read);
	return (line);
}
