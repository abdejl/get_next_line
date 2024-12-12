/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abjellal <abjellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:02:15 by abjellal          #+#    #+#             */
/*   Updated: 2024/12/12 12:44:47 by abjellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(int fd, char *str)
{
    char tmp_buff[BUFFER_SIZE + 1];
    int num_of_bytes;
    char *new_str;

    num_of_bytes = read(fd, tmp_buff, BUFFER_SIZE);
    if (num_of_bytes < 0)
        return (NULL);
    tmp_buff[num_of_bytes + 1] = '\0';
    if (!str)
    {
        str = malloc(1);
        if (!str)
            return (NULL);
        str[0] = '\0';
    }
    new_str = ft_strjoin(str, tmp_buff);
    if (!new_str)
    {
        free(str);
        return (NULL);
    }
    free(str);
    return (new_str);
}
int main()
{
    char *buff;
    int fd = open("test.txt", O_CREAT);
    if (fd < 0)
        return (1);
    printf("%s", buff);
    free(buff);
    close(fd);
}

char *ft_new_line(char *str)
{
    int i;
    char *line;

    i = 0;
    while (str[i] != '\n' && str[i])
        i++;
    line = malloc(i + 2);
    if (!line)
        return (NULL);
    i = 0;
    while (str[i] != '\n')
    {
        line[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        line[i] = '\n';
    }
    i++;
    line[i] = '\0';
    return (line);
}

char *ft_remaining(char *str)
{
    int i;
    char *remaining;
    int j;
    
    i = 0;
    j = 0;
    while (str[i] != '\n' && str[i])
        i++;
    if (str[i] == '\0')
        return (NULL);
    remaining = malloc(ft_strlen(str + i + 1) +1);
    if (!remaining)
        return (NULL);
    i++;
    while (str[i])
    {
        remaining[j] = str[i];
        i++;
        j++;
    }
    remaining[j] = '\0';
    return(remaining);
}

char *get_next_line(int fd)
{
    static char *data_read = NULL; 
    char *line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    data_read = ft_read(fd, data_read);
    if (!data_read)
        return (NULL);
    if (ft_strchr(data_read, '\n'))
    {
        line = ft_new_line(data_read);
        data_read = ft_remaining(data_read);
    }
    else if (*data_read)
    {
        line = data_read;
        data_read = NULL;
    }
    return (line);
}
// int main()
// {
//     char str[] = "hellooo\njgflkjjhg\nskldjks\n1234";
//     printf("%s\n", ft_new_line(str));
//     printf("%s", ft_remaining(str));
// }


