/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-vli <cvan-vli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 14:41:35 by cvan-vli      #+#    #+#                 */
/*   Updated: 2024/01/18 16:59:20 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

char	*a_nl(char *static_buffer)
{
	char	*new_line;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	new_line = malloc((ft_strlen(static_buffer) - i) * sizeof(char));
	if (!new_line)
	{
		// free(static_buffer);
		return (NULL);
	}
	i++;
	while (i < ft_strlen(static_buffer) && static_buffer[i])
		new_line[j++] = static_buffer[i++];
	new_line[j] = '\0';
	free(static_buffer);
	return (new_line);
}

char	*b_nl(char *static_buffer)
{
	char	*new_line;
	int		i;

	i = 0;
	while (static_buffer[i] != '\n' && static_buffer[i])
		i++;
	new_line = malloc((i + 2) * sizeof(char));
	if (!new_line)
		return (0);
	i = 0;
	while (static_buffer[i] != '\n' && static_buffer[i])
	{
		new_line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
	{
		new_line[i] = static_buffer[i];
		new_line[i + 1] = '\0';
	}
	else
		new_line[i] = '\0';
	return (new_line);
}

char	*read_buffs(char *static_buffer, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(static_buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		static_buffer = str_join(static_buffer, buffer);
	}
	free(buffer);
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	// static char	static_buffer[BUFFER_SIZE + 1];
	static char	*static_buffer;
	char		*result;
	
	if (!static_buffer)
		static_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (static_buffer)
			free(static_buffer);
		return (NULL);
	}
	static_buffer = read_buffs(static_buffer, fd);
	// if (!static_buffer)
	// 	return (NULL);
	result = b_nl(static_buffer);
	if (ft_strlen(result) == 0)
	{
		if (result)
			free(result);
		return (NULL);
	}
	static_buffer = a_nl(static_buffer);
	return (result);
}

int	main(void)
{
	char	*str;
	int		fd;
	int		i;
	int		j;

	j = 1;
	i = 0;
	// printf("here\n");
	fd = open("text.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		write(1, str, ft_strlen(str));
		free(str);
		str = get_next_line(fd);
		// printf("%d: %s", j, str);
		j++;
		i++;
	}
}
