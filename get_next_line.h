/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 14:30:36 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/01/16 15:13:53 by cavan-vl      ########   odam.nl         */
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
# include <stdio.h>

#define ERROR -1
#define SUCCESS 0

typedef struct s_list
{
	char			line[BUFFER_SIZE + 1];
	struct s_list	*next;
}				t_list;

int		len_nl(t_list *list);
int		make_list(t_list **list, int fd, char *buffer);
t_list	*ft_lstlast(t_list *lst);
void	copy_string(t_list	*list, char *line, int check);
void	append_node(t_list **list, char *buffer);
int		find_nl(t_list *list);
void	clean_up(t_list **list);
char	*fetch_line(t_list *list);
char	*get_next_line(int fd);
char	*fetch_buffer(t_list *list, char *buffer);
void	dealloc(t_list **list, t_list *clean_node, char *buf);

#endif
