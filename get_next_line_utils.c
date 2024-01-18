/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-vli <cvan-vli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 11:36:10 by cvan-vli      #+#    #+#                 */
/*   Updated: 2024/01/18 16:59:39 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*str_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1)
		s1 = (char *)malloc(1 * sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		s3[i] = s1[i];
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (s3);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

char	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (*s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

