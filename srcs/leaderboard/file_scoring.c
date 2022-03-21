#include "file_scoring.h"

int ft_clean_quit(t_score **head, int fd, char *line, int error)
{
	if (fd > 0)
		close(fd);
	if (line)
		free(line);
	destroy_list(head);
	
    // mvprintw(10, 10, "Error When reading the file"); // message debug temporaire
	return (error);
}

int get_scores_from_file(t_score **head)
{
	char *line = NULL;
	*head = NULL;
	int fd = open("scores.txt", O_RDONLY);

	if (fd < 0)
		return ft_clean_quit(head, fd, line, ERROR_FD);
	while((line = get_next_line(fd)) != NULL)
	{
		if (!check_line_format(line))
			free(line);
		else if(!add_line_to_score(line, head))
		{
			free(line);
			return ft_clean_quit(head, fd, NULL, ERROR_MALLOC);
		}
	}
	get_next_line(-1);
	close(fd);
	return (SUCCESS);
}

int put_score_to_file(t_score *head, char *pseudo)
{
	int i = 0;
	int fd = open("scores.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU);
	if (fd < 0)
		return (ERROR_FD);
	while(head && i < 15)
	{
		if (!head->pseudo)
		{
			write(fd, pseudo, ft_strlen(pseudo));
			write(fd, ":", 1);
			ft_putnbr_fd(head->score, fd);
		}
		else //just magic ask Auguste if you need to understand
		{
			head->pseudo[ft_strlen(head->pseudo)] = ':';
			write(fd, head->pseudo, ft_strlen(head->pseudo));
		}
		write(fd, "\n", 1);
		head = head->next;
		i++;
	}
	close(fd);
	return (SUCCESS);
}

int check_pseudo_format(char *pseudo)
{
	for(int i = 0; pseudo[i]; i++)
	{
		if(!ft_isalnum(pseudo[i]))
			return (0);
	}
	if (ft_strlen(pseudo) > 20)
		return (0);
	return (1);
}

int check_line_format(char *line)
{
	int i = 0;

	if (!line || !*line)
		return (0);

	while (line[i] && line[i] != ':') //lire le pseudo jusqu'au separateur
	{
		if (!ft_isalnum(line[i]))
			return (0);
		i++;
	}
	if (!line[i] )
		return (0);//si il n'y a rien apres le separateur
	i++;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return(0);
		i++;
	}
	return (1);
}

int add_line_to_score(char *line, t_score **head)
{
	if (!*head)
	{
		*head = create_score(separate_pseudo_score(line), line);
		if (!*head)
			return (0);
	}
	else
	{
		t_score *ptr_temp = create_score(separate_pseudo_score(line), line);
		if (!ptr_temp)
			return(0);
		add_score(ptr_temp, head);
	}
	return (1);
}

// fonction qui met un \0 à la fin du pseudo et qui retourne la valeur du score associée
int separate_pseudo_score(char *line) 
{
	int i = 0;
	while (line[i] != ':')
		i++;
	line[i] = '\0';
	i++;
	return (ft_atoi(&line[i]));
}

t_score *create_score(int score, char *pseudo)
{
	t_score *ret = malloc(sizeof(t_score));
	if (!ret)
		return (NULL);

	ret->score = score;
	ret->pseudo = pseudo;
	ret->next = NULL;
	return (ret);
}

void add_score(t_score *to_add, t_score **head)
{
	if(!head)
		return;
	if (!*head)
	{
		*head = to_add;
		return;
	}
	t_score *ptr_temp = *head;

	if (to_add->score > (*head)->score)
	{
		to_add ->next = *head;
		*head = to_add;
		return;
	}
	while (ptr_temp->next && ptr_temp->next->score > to_add->score)
		ptr_temp = ptr_temp->next;
	to_add->next = ptr_temp->next;
	ptr_temp->next = to_add;
}

void destroy_list(t_score **head)
{
	t_score *ptr_temp = *head;
	
	while (*head)
	{
		ptr_temp = (*head)->next;
		if ((*head)->pseudo)
			free((*head)->pseudo);
		free(*head);
		*head = ptr_temp;
	}
}
