/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 14:01:48 by cavan-vl      #+#    #+#                 */
/*   Updated: 2023/12/07 20:09:38 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// fetch next line
{
	int	
}

void	append_node(t_list **list, char *buffer)
{
	t_list	*last_node;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	last_node = ft_lstlast(&list);
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->line = buffer;
	new_node->next = NULL;
}

int	find_newline(t_list *list)
{
	int	i;

	i = 0;
	while (list->line[i])
	{
		if (list->line[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

void	create_list(t_list **list, int fd)
{
	char	*buffer;
	int		chars;

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
	// fetch new line
}
