/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaure <afaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:00:52 by afaure            #+#    #+#             */
/*   Updated: 2021/08/17 00:19:09 by afaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buffer	*gnl_lstfind_create(int fd, t_buffer *buff_list)
{
	t_buffer	*ptr;
	t_buffer	*new;

	if (!buff_list)
		return (NULL);
	ptr = buff_list;
	while (ptr->next && ptr->fd != fd)
		ptr = ptr->next;
	if (!ptr->next && ptr->fd != fd)
	{
		new = malloc(1 * sizeof(t_buffer));
		if (!new)
			return (NULL);
		new->fd = fd;
		new->leftover = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (new->leftover)
			new->leftover[0] = '\0';
		new->next = NULL;
		ptr->next = new;
		return (new);
	}
	return (ptr);
}

void	*gnl_del_lst(t_buffer **buff_list, char **line)
{
	t_buffer	*temp;

	if (line && *line)
	{
		free(*line);
		*line = NULL;
	}
	while (*buff_list)
	{
		temp = (*buff_list)->next;
		if ((*buff_list)->leftover)
			free((*buff_list)->leftover);
		free(*buff_list);
		(*buff_list) = temp;
	}
	return (NULL);
}

void	gnl_lstdel_one(t_buffer **buff_list, t_buffer *lst, char **line)
{
	t_buffer	*ptr;

	if (*buff_list)
	{
		ptr = *buff_list;
		if (*buff_list == lst)
		{
			free((*buff_list)->leftover);
			*buff_list = (*buff_list)->next;
			free(ptr);
		}
		else
		{
			while (ptr->next->fd != lst->fd)
				ptr = ptr->next;
			ptr->next = lst->next;
			free(lst->leftover);
			free(lst);
		}
	}
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
}

t_buffer	*gnl_lstinit(int fd)
{
	t_buffer	*ret;

	ret = malloc(sizeof(t_buffer));
	if (!ret)
		return (NULL);
	ret->fd = fd;
	ret->ret = 0;
	ret->leftover = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (ret->leftover)
		ret->leftover[0] = '\0';
	ret->next = NULL;
	return (ret);
}
