/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abjellal <abjellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:02:23 by abjellal          #+#    #+#             */
/*   Updated: 2024/12/14 09:44:49 by abjellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(const char *str)
{
    int i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}


char *ft_strchr(const char *s, int c)
{
    int i = 0;

    if (!s)
        return (NULL);
    while (s[i])
    {
        if ((unsigned char)s[i] == (unsigned char)c)
            return ((char *)(s + i));
        i++;
    }
    if (c == '\0')
        return ((char *)(s + i));
    return (NULL);
}


char *ft_strjoin(char const *s1, char const *s2)
{
    char *ptr;
    int i = 0;
    int k = 0;
    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);

    ptr = malloc((len1 + len2 + 1) * sizeof(char));
    if (!ptr)
        return (NULL);
    while (i < len1)
    {
        ptr[i] = s1[i];
        i++;
    }
    while (k < len2)
    {
        ptr[i + k] = s2[k];
        k++;
    }
    ptr[i + k] = '\0';
    return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (s[j])
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}