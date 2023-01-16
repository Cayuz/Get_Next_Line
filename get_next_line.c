/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-vli <cvan-vli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 14:41:35 by cvan-vli      #+#    #+#                 */
/*   Updated: 2023/01/16 15:42:01 by cvan-vli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_buffs(char *static_buffer, char *buffer)
{
	char	*new_line;
	int		i;

	i = 0;
	new_line = malloc((ft_strlen(buffer) + ft_strlen(static_buffer))
			*sizeof(char *))
	while (buffer || static_buffer)
	{
		new_line[i] = static_buffer;
	}
	return (0);
}

char	*read_buffs(char *static_buffer, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, "\n"))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		static_buffer = ft_strjoin(static_buffer, buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_buffer = read_buffs(static_buffer, fd);
}
