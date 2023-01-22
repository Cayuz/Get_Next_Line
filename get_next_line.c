/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-vli <cvan-vli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 14:41:35 by cvan-vli      #+#    #+#                 */
/*   Updated: 2023/01/22 12:18:00 by cvan-vli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

int	BUFFER_SIZE = 1;

char	*a_nl(char *static_buffer)
{
	char	*new_line;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	new_line = malloc((ft_strlen(static_buffer) - i) * sizeof(char *));
	if (!new_line)
		return (NULL);
	i++;
	while (static_buffer[i])
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
	new_line = malloc((i + 2) * sizeof(char *));
	if (!new_line)
		return (NULL);
	i = 0;
	while (static_buffer[i] != '\n' && static_buffer[i])
	{
		new_line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
		new_line[i] = static_buffer[i];
	new_line[++i] = '\0';
	return (new_line);
}

char	*read_buffs(char *static_buffer, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(static_buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		static_buffer = str_join(static_buffer, buffer);
	}
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*result;

	static_buffer = read_buffs(static_buffer, fd);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = b_nl(static_buffer);
	static_buffer = a_nl(static_buffer);
	return (result);
}

int	main(void)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	str = get_next_line(fd);
	while (i < BUFFER_SIZE)
	{
		printf("%d: %s", i, str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
}
