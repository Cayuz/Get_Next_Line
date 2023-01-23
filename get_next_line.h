/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-vli <cvan-vli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 15:38:11 by cvan-vli      #+#    #+#                 */
/*   Updated: 2023/01/23 11:44:34 by cvan-vli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*read_buffs(char *static_buffer, int fd);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*str_join(char *s1, char *s2);
char	ft_strchr(char *s, char c);

#endif