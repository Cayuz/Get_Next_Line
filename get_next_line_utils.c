/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-vli <cvan-vli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 11:36:10 by cvan-vli      #+#    #+#                 */
/*   Updated: 2023/01/16 15:41:51 by cvan-vli      ########   odam.nl         */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;

	new_string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_string == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(new_string, s1, (ft_strlen(s1) + 1));
	ft_strlcat(new_string, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (new_string);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dst_len;
	size_t		src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
	{
		return (size + src_len);
	}
	while (dst_len < size - 1 && src[i])
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (src_len + (ft_strlen(dst) - i));
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	while (i < (dstsize - 1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

int	main(void)
{
	char *s1 = "Hallo";
	char *s2 = "Doei";

	printf("%s", ft_strjoin(s1, s2));
}