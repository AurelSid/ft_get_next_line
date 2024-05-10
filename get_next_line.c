/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:27:34 by asideris          #+#    #+#             */
/*   Updated: 2024/05/10 15:57:01 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*init_empty_string(void)
{
	char	*str;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

void	ft_next_line(char **buffer, int last_new_line)
{
	char	*tmp;

	tmp = *buffer;
	*buffer = ft_substr(*buffer, last_new_line, ft_strlen(*buffer));
	free(tmp);
	return ;
}
ssize_t	ft_fill_line(char **buffer, int fd)
{
	ssize_t	readed_count;
	char	*read_buff;

	if (BUFFER_SIZE < 1 || !BUFFER_SIZE || read(fd, 0, 0) < 0 || fd < 0 || !fd)
		return (0);
	if (!(*buffer))
		*buffer = init_empty_string();
	if (!(*buffer))
		return (0);
	read_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	
	if (!read_buff)
		return (0);
	readed_count = read(fd, read_buff, BUFFER_SIZE);
	while (readed_count > 0)
	{
		read_buff[readed_count] = '\0';
		*buffer = ft_strjoin(*buffer, read_buff);
		if (charchr(*buffer, '\n') >= 0)
			break ;
		readed_count = read(fd, read_buff, BUFFER_SIZE);
	}
	free(read_buff);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			last_new_line;
	char		*line;

	if (!ft_fill_line(&buffer, fd))
		free(buffer);
	last_new_line = charchr(buffer, '\n');
	if (last_new_line >= 0)
	{
		line = ft_substr(buffer, 0, last_new_line + 1);
		ft_next_line(&buffer, last_new_line + 1);
	}
	else
	{
		line = ft_substr(buffer, 0, ft_strlen(buffer));
		free(buffer);
		buffer = NULL;
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
/*int	main(void)
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	if (!fd)
		perror("Fd not valid");

	printf("line : [%s], \n", get_next_line(fd));


	close(fd);
}*/