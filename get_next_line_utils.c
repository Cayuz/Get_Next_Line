/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/30 16:16:37 by cavan-vl      #+#    #+#                 */
/*   Updated: 2023/12/07 19:58:23 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(nmemb * size);
	if (!ptr || ptr == NULL)
		return(NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return(ptr);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
