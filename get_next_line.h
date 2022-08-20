#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
#include <unistd.h>

char    *get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *string, int searchedChar );
char	*ft_strdup(const char *src);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *theString);
#endif