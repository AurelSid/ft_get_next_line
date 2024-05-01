/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:22:29 by asideris          #+#    #+#             */
/*   Updated: 2024/04/29 17:01:15 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*cache_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		ft_free_cache(&cache_buffer);
		return (NULL);
	}
	if (cache_buffer == NULL)
		cache_buffer = ft_strdup("");
	if (!cache_buffer)
		return (NULL);
	line = (ft_check_cache(fd, &cache_buffer));
	if (!line)
		ft_free_cache(&cache_buffer);
	return (line);
}

char	*ft_check_cache(int fd, char **cache)
{
	int		readresult;
	char	*tmp;

	if (ft_strchr(*cache, '\n'))
	{
		tmp = ft_substr(*cache, 0, ft_strchr(*cache, '\n') - *cache + 1);
		*cache = ft_memmove(*cache, ft_strchr(*cache, '\n') + 1,
				ft_strlen(ft_strchr(*cache, '\n') + 1) + 1);
	}
	else
	{
		readresult = ft_fill_line(cache, fd);
		if (readresult <= 0)
		{
			if (ft_strlen(*cache) == 0 || readresult < 0)
			{
				ft_free_cache(cache);
				return (NULL);
			}
			else
			{
				tmp = (ft_substr(*cache, 0, ft_strchr(*cache, '\0') - *cache
							+ 1));
				*cache[0] = '\0';
				return (tmp);
			}
		}
		return (ft_check_cache(fd, cache));
	}
	return (tmp);
}
int	ft_fill_line(char **cache, int fd)
{
	int		readresult;
	char	read_buffer[BUFFER_SIZE + 1];
	char	*tmp;

	ft_bzero(read_buffer, BUFFER_SIZE + 1);
	readresult = read(fd, read_buffer, BUFFER_SIZE);
	if (readresult < 0)
	{
		ft_free_cache(cache);
		return (readresult);
	}
	tmp = *cache;
	*cache = ft_strjoin(*cache, read_buffer);
	if (tmp)
		free(tmp);
	return (readresult);
}
void	ft_free_cache(char **cache)
{
	if (*cache)
		free(*cache);
	*cache = NULL;
	return ;
}

/*#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("line : %s", get_next_line(fd));
	printf("line : %s", get_next_line(fd));
	printf("line : %s", get_next_line(fd));
	printf("line : %s", get_next_line(fd));
	printf("line : %s", get_next_line(fd));
	close(fd);
}*/
