

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<unistd.h>
# include<fcntl.h> 
# include<stdlib.h>

int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_line(char *str);
char	*get_rest(char *str);
int		newline(char *str);
char	*get_next_line(int fd);

#endif