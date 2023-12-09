/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 14:01:48 by cavan-vl      #+#    #+#                 */
/*   Updated: 2023/12/09 15:19:56 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_up(t_list **list)
{
	t_list	*clean_node;
	t_list	*last_node;
	int		i;
	int		j;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	last_node = ft_lstlast(*list);
	if (!buffer || !last_node)
		return ;
	i = 0;
	j = 0;
	while (last_node->line[i] && last_node->line[i] != '\n')
		i++;
	while (last_node->line[i] && last_node->line[++i])
	{
		buffer[j] = last_node->line[i];
		j++;
	}
	clean_node->line = buffer;
	clean_node->next = NULL;
}

char	*fetch_line(t_list *list)
{
	int		len_to_newline;
	char	*line;

	if (!list)
		return (NULL);
	len_to_newline = find_newline(list);
	line = malloc(len_to_newline + 1);
	if (!line)
		return (NULL);
	copy_string(list, line);
	return (line);
}

void	create_list(t_list **list, int fd)
{
	char	*buffer;
	int		chars;

	if(!list)
		return ;
	while (!find_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		chars = read(fd, buffer, BUFFER_SIZE);
		if (!chars)
		{
			free(buffer);
			return ;
		}
		buffer[chars] = '\0';
		append_node(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0 < 0))
	{
		line = NULL;
		return (NULL);
	}
	create_list(&list, fd);
	line = fetch_line(list);
	clean_up(&list);
}
