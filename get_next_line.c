/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:22:29 by asideris          #+#    #+#             */
/*   Updated: 2024/04/28 18:27:22 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_get_remains(char *line_buffer, char *remains_buffer);
char	*ft_populate_line(char *remains_buffer, char *read_buffer, int fd);
char	*get_next_line(int fd)
{
	char		*line_buffer;
	char		*read_buffer;
	static char	*remains_buffer;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	line_buffer = ft_populate_line(remains_buffer, read_buffer, fd);
	remains_buffer = ft_get_remains(line_buffer, remains_buffer);
	if (!line_buffer)
		return (NULL);
	return (line_buffer);
}

char	*ft_populate_line(char *remains_buffer, char *read_buffer, int fd)
{
	ssize_t	curr_reading;
	char	*tmp;

	curr_reading = 1;
	while (curr_reading > 0)
	{
		curr_reading = read(fd, read_buffer, BUFFER_SIZE);
		if (curr_reading < 0)
		{
			printf("Error reading file.\n");
			return (NULL);
		}
		printf("Bytes read: %ld\n", curr_reading);
		if (!remains_buffer)
			remains_buffer = ft_strdup("");
		if (curr_reading == 0 || ft_strchr(read_buffer, '\n'))
			break ;
		tmp = remains_buffer;
		remains_buffer = ft_strjoin(tmp, read_buffer);
		free(tmp);
		tmp = NULL;
	}
	return (remains_buffer);
}

char	*ft_get_remains(char *line_buffer, char *remains_buffer)
{
	int	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	remains_buffer = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	printf("Remains: %s\n", remains_buffer);
	return (remains_buffer);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDWR);
	printf("Line: %s\n", get_next_line(fd));
	return (0);
}
