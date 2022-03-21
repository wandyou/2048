/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaure <afaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:24:04 by afaure            #+#    #+#             */
/*   Updated: 2022/03/19 18:06:07 by afaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

typedef struct s_buffer
{
	char					*leftover;
	int						ret;
	int						fd;
	struct s_buffer			*next;
}				t_buffer;

char		*get_next_line(int fd);
int			gnl_read_line(int fd, char *leftover, char **line);
int			gnl_offset(char *leftover);
char		*gnl_strjoin(char *line, char *leftover);
int			gnl_strcat(char *line, char *leftover);
t_buffer	*gnl_lstfind_create(int fd, t_buffer *buff_list);
t_buffer	*gnl_lstinit(int fd);
void		*gnl_del_lst(t_buffer **buff_list, char **line);
void		gnl_lstdel_one(t_buffer **buff_list, t_buffer *lst, char **line);

#endif
