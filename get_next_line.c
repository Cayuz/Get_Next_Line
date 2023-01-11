/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-vli <cvan-vli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 14:41:35 by cvan-vli      #+#    #+#                 */
/*   Updated: 2023/01/11 17:36:02 by cvan-vli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include 

char	*concatenate(char *fin_str, char *buf_str, int fin_size, int buf_size)
{
	return (0);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*final_str;
	ssize_t			bytes_read;

	if (fd < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n')
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
		i++;
	}
	final_str = concatenate;
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("text.txt", 0_RONLY);
	str = get_next_line(fd);
}