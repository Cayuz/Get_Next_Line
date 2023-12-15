/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 14:30:36 by cavan-vl      #+#    #+#                 */
/*   Updated: 2023/12/15 17:38:37 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}				t_list;

int		find_newline(t_list *list);
void	create_list(t_list **list, int fd);
t_list	*ft_lstlast(t_list *lst);
void	copy_string(t_list	*list, char *line);
void	append_node(t_list **list, char *buffer);
int		find_newline(t_list *list);
void	clean_up(t_list **list);
char	*fetch_line(t_list *list);
char	*get_next_line(int fd);
void	free_list(t_list *list);

#endif
