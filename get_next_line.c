/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 14:01:48 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/01/16 18:14:52 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_list(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(*list);
		*list = tmp;
	}
}

char	*fetch_line(t_list *list)
{
	char	*line;
	int		i = 0;

	if (!list)
		return (NULL);
	line = malloc(len_nl(list) + 1);
	if (!line)
		return (NULL);
	// copy_string(list, line, find_nl(list->line));
	while (list->line[i] != '\0')
	{
		line[i] = list->line[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	append_node(t_list **list, char *buffer)
{
	t_list	*new_node;
	int		i;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;

	if (list == NULL)
		*list = new_node;
	else
		ft_lstlast(*list)->next = new_node;

	if (find_nl(buffer) == -1)
		copy_string(list, buffer, BUFFER_SIZE + 1);
	else
		copy_string(list, buffer, find_nl(buffer) + 1);

	new_node->next = NULL;
}

t_list	*make_list(t_list *list, int fd, char *buffer)
{
	int	chars;

	while (find_nl(buffer) == -1 && chars != 0)
	{
		chars = read(fd, buffer, BUFFER_SIZE);
		if (chars == ERROR)
		{
			clean_list(list);
			return (NULL);
		}
		buffer[chars] = '\0';
		append_node(list, buffer);
	}
	return (list);
}

char	*get_next_line(int fd)
{
	t_list		*list;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	list = make_list(&list, fd, buffer);
	if (!list)
		return (NULL);
	line = fetch_line(list);
	clean_list(&list);
	//manage_buffer -> op naar alles na '\n'!
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("Line: %s\n", line);
		free(line);
	}
}
