/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 14:01:48 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/01/16 15:45:35 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	clean_up(t_list **list)
// {
// 	t_list	*last_node;
// 	t_list	*clean_node;
// 	int		i;
// 	int		k;
// 	char	buf[BUFFER_SIZE + 1];

// 	clean_node = malloc(sizeof(t_list));
// 	if (!clean_node)
// 		return ;
// 	last_node = ft_lstlast(*list);
// 	i = 0;
// 	k = 0;
// 	if (last_node->line[BUFFER_SIZE - 1] != '\0')
// 		last_node->line[BUFFER_SIZE - 1] = '\0';
// 	while (last_node->line[i] && last_node->line[i] != '\n')
// 		++i;
// 	while (last_node->line[i] && last_node->line[++i])
// 		buf[k++] = last_node->line[i];
// 	buf[k] = '\0';
// 	copy_string(clean_node, buf, 0);
// 	clean_node->next = NULL;
// 	dealloc(list, clean_node, buf);
// }

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

// void	append_node(t_list **list, char *buffer)
// {
// 	t_list	*last_node;
// 	t_list	*new_node;
// 	int		i;

// 	new_node = malloc(sizeof(t_list));
// 	if (!new_node)
// 		return ;
// 	last_node = ft_lstlast(*list);
// 	if (!last_node)
// 		*list = new_node;
// 	else
// 		last_node->next = new_node;
// 	// copy_string(new_node, buffer, 1);
// 	i = 0;
// 	while(buffer[i])
// 	{
// 		new_node->line[i] = buffer[i];
// 		i++;
// 	}
// 	new_node->next = NULL;
// }
void	append_node(t_list **list, char *buffer)
{
	t_list	*new_node;
	int		i;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (list == NULL)
		*list = new_node;
	ft_lstlast(*list)->next = new_node;
	// copy_string(new_node, buffer, 1);
	if (find_nl(buffer) == -1)
		copy_string(list, buffer, BUFFER_SIZE + 1);
	else
		copy_string(list, buffer, find_nl(buffer) + 1);
	new_node->next = NULL;
}

char	*fetch_line(t_list *list)
{
	char	*line;

	if (!list)
		return (NULL);
	line = malloc(len_nl(list) + 1);
	if (!line)
		return (NULL);
	copy_string(list, line, 0);
	return (line);
}

int	make_list(t_list **list, int fd, char *buffer) // single pointer, return een lijst?
{
	int		chars;

	while (find_nl(buffer) == 0 && chars != 0)
	{
		chars = read(fd, buffer, BUFFER_SIZE);
		if (chars == ERROR) // error, alles opruimen
			return (ERROR);
		buffer[chars] = '\0';
		append_node(list, buffer);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	t_list	*list = NULL;
	char	*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (make_list(&list, fd, buffer) == ERROR)
		return (NULL);
	// if (!list)
	// 	return (NULL);
	line = fetch_line(list);
	clean_up(&list);
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
