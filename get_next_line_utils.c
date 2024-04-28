/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:09:32 by asideris          #+#    #+#             */
/*   Updated: 2024/04/28 17:13:22 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	s2 = malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	n;

	i = 0;
	n = ft_strlen(s);
	while (i <= n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (0);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	sizes1;
	size_t	sizes2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	sizes1 = ft_strlen(s1);
	sizes2 = ft_strlen(s2);
	s = malloc(sizeof(char) * (sizes1 + sizes2 + 1));
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s[j + i] = s2[j];
		j++;
	}
	s[j + i] = '\0';
	return (s);
}

char	*ft_substr(char const *s, int start, size_t len)
{
	char	*s2;

	if (start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (ft_strlen(s) - start < (int)len)
		len = ft_strlen(s) - start;
	s2 = (char *)ft_calloc(len + 1, sizeof(char));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s + start, len);
	return (s2);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*i;

	i = malloc(count * size);
	if (!i)
	{
		return (NULL);
	}
	ft_bzero(i, count * size);
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	long unsigned int	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}
void	ft_bzero(void *s, size_t n)
{
	long unsigned int i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = 0;
		i++;
	}
}