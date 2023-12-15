/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/30 16:16:37 by cavan-vl      #+#    #+#                 */
/*   Updated: 2023/12/15 17:56:59 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	copy_string(t_list	*list, char *line)
{
	int	i;
	int	j;

	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->line[i])
		{
			if (list->line[i] == '\n')
			{
				line[j++] = '\n';
				line[j] = '\0';
				return ;
			}
			line[j++] = list->line[i++];
		}
		list = list->next;
	}
	line[j] = '\0';
}

void	append_node(t_list **list, char *buffer)
{
	t_list	*last_node;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node || !list)
		return ;
	last_node = ft_lstlast(*list);
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

	if (NULL == list)
		return (0);
	if (list->next)
		list = list->next;
	while (list)
	{
		i = 0;
		while (list->line[i] && i < BUFFER_SIZE)
		{
			if (list->line[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

void	free_list(t_list *list)
{
	t_list	*current;

	current = list;
	while (current)
	{
		list = list->next;
		free(current->line);
		free(current);
		current = list;
	}
}

