/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaure <afaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:23:05 by afaure            #+#    #+#             */
/*   Updated: 2021/10/30 16:17:08 by afaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buffer	*buff_list;
	t_buffer		*current_fd;
	char			*line;

	if (!buff_list)
		buff_list = gnl_lstinit(fd);
	current_fd = gnl_lstfind_create(fd, buff_list);
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line || BUFFER_SIZE < 1
		|| !current_fd || !current_fd->leftover || fd == -1)
		return (gnl_del_lst(&buff_list, &line));
	line[0] = '\0';
	if (ft_strlen(current_fd->leftover)
		&& gnl_strcat(line, current_fd->leftover))
		return (line);
	current_fd->ret = gnl_read_line(fd, current_fd->leftover, &line);
	if (current_fd->ret == -2)
		gnl_del_lst(&buff_list, &line);
	else if (current_fd->ret < 1)
		gnl_lstdel_one(&buff_list, current_fd, &line);
	return (line);
}

int	gnl_read_line(int fd, char *leftover, char **line)
{
	int	ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, leftover, BUFFER_SIZE);
		if (ret == 0)
			return (-1);
		leftover[ret] = '\0';
		*line = gnl_strjoin(*line, leftover);
		if (!*line)
			return (-2);
		if ((int)ft_strlen(leftover) != ret)
			return (ret);
	}
	if (ret < 0 && *line)
	{
		free(*line);
		*line = NULL;
		ret = -2;
	}
	return (ret);
}

char	*gnl_strjoin(char *line, char *leftover)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = malloc((ft_strlen(line) + ft_strlen(leftover) + 1) * sizeof(char));
	if (!ret)
	{
		free(line);
		return (NULL);
	}
	while (line[i])
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	free(line);
	gnl_strcat(ret, leftover);
	return (ret);
}

int	gnl_strcat(char *line, char *leftover)
{
	size_t	i;

	i = 0;
	while (*line)
		line++;
	while (leftover[i] && leftover[i] != '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	line[i] = '\0';
	if (leftover[i] == '\n')
	{
		gnl_offset(leftover);
		return (1);
	}
	return (0);
}

int	gnl_offset(char *leftover)
{
	size_t	i;
	size_t	offset;

	offset = 0;
	i = 0;
	while (leftover[offset] != '\n')
		offset++;
	offset += 1;
	while (leftover[i + offset])
	{
		leftover[i] = leftover[i + offset];
		i++;
	}
	leftover[i] = '\0';
	return (1);
}
