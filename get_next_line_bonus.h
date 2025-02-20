/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abjellal <abjellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:12:27 by abjellal          #+#    #+#             */
/*   Updated: 2024/12/26 10:23:06 by abjellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_new_line(char *line);
char	*ft_read(int fd, char *str);
char	*ft_remaining(char *str);

#endif
