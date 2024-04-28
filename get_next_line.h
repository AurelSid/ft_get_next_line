#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, int start, size_t len);
char	*get_next_line(int fd);
char	*ft_populate_line(char *remains_buffer, char *read_buffer, int fd);
char	*ft_get_remains(char *line_buffer, char *remains_buffer);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);



#endif