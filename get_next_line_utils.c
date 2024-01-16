/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/30 16:16:37 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/01/16 15:26:15 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next)
		lst = lst->next;
	return (lst);
}

void	copy_string(t_list	*list, char *buffer, int check)
{
	int	i;
	int	j;

	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (buffer[i])
		{
			if (check)
			{
				if (buffer[i] == '\n')
				{
					list->line[j++] = '\n';
					list->line[j] = '\0';
					return ;
				}
			}
			list->line[j++] = buffer[i++];
		}
		list->line[j] = '\0';
		list = list->next;
	}
}

// void	copy_string(t_list	*list, char *line, int check)
// {
// 	int	i;
// 	int	j;

// 	if (!list)
// 		return ;
// 	j = 0;
// 	while (list)
// 	{
// 		i = 0;
// 		while (list->line[i])
// 		{
// 			if (check)
// 			{
// 				if (list->line[i] == '\n')
// 				{
// 					line[j++] = '\n';
// 					line[j] = '\0';
// 					return ;
// 				}
// 			}
// 			line[j++] = list->line[i++];
// 		}
// 		list = list->next;
// 	}
// 	line[j] = '\0';
// }

int	find_nl(t_list *list) // <- string?
{
	int	i;

	if (!list)
		return (0);
	i = 0;
	while (list)
	{
		while (list->line[i] && i < BUFFER_SIZE)
		{
				if (list->line[i] == '\n')
					return(i);
			i++;
		}
		list = list->next;
	}
	return (-1);
}

int	len_nl(t_list *list) 
{
	int	i;
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->line[i])
		{
			if (list->line[i] == '\n')
				return (len + 1);
			len++;
			i++;
		}
		list = list->next;
	}
	return (len);
}

void	dealloc(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	if (clean_node->line[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
