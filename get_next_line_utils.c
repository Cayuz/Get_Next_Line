/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/30 16:16:37 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/01/16 18:15:00 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next)
		lst = lst->next;
	return (lst);
}

void	copy_string(t_list *list, char *buffer, int size)
{
	int	i;
	int	j;

	if (list == NULL)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while(buffer[i] != '\0' && i < size)
		{
			if (buffer[i] == '\n')
				list->line[i] = buffer[i];
			i++;
		}
		list->line[]
	}
}

int	find_nl(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			return (i);
		i++;
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
