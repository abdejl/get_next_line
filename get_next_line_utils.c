/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abjellal <abjellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:02:23 by abjellal          #+#    #+#             */
/*   Updated: 2024/12/09 13:11:04 by abjellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(const char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    if (c == '\0')
    {
        return ((char *)(s + i));
    }
    while (s[i])
    {
        if ((unsigned char)s[i] == (unsigned char)c)
		{
			return ((char *)(s + i));
		}
		i++;
    }
    return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	i = 0;
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	k = 0;
	while (k < ft_strlen(s2))
	{
		ptr[i + k] = s2[k];
		k++;
	}
	ptr[i + k] = '\0';
	return (ptr);
}
