/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abjellal <abjellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:02:15 by abjellal          #+#    #+#             */
/*   Updated: 2024/12/10 12:21:59 by abjellal         ###   ########.fr       */
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
    tmp_buff[num_of_bytes] = '\0';
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

char *ft_line(char *str)
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
    
}
// int main()
// {
//     char str[] = "hellooo\njgflkjjhg\nskldjks\n1234";
//     printf("%s\n", ft_line(str));
//     printf("%s", ft_remaining(str));
// }


int main()
{
    char *buff;
    int fd = open("test.txt", O_RDONLY);
    int fd2 = open("test1.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    buff = ft_read(fd, NULL);
    buff = ft_read(fd2, NULL);
    if (!buff)
    {
        close(fd);
        return (1);
    }
    printf("%s", buff);
    printf("%s", buff);
    free(buff);
    close(fd);
}