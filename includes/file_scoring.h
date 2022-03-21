#ifndef FILE_SCORING_H
# define FILE_SCORING_H

#include "libft.h"
#include "board.h"
#include "fcntl.h"
#include <ncurses.h>

# define SUCCESS		1
# define ERROR_FD		-1
# define ERROR_MALLOC	-2
# define ERROR_FORMAT	-3


//functions for other users

//cette fonction va essayer de lire un fichier et remplir une liste chainée pointée par head puis renvoyer
// un des define du header
int		get_scores_from_file(t_score **head);

// fonction qui ecris les scores dans un fichier, peut retourner SUCESS ou ERROR_FD
int	put_score_to_file(t_score *head, char *pseudo);

//créé un maillon score à partir d'un int et d'une string
t_score	*create_score(int score, char *pseudo);

//ajoute un maillon score au bon endroit dans la liste chainée
void	add_score(t_score *to_add, t_score **head);

//détruit entierement la liste
void	destroy_list(t_score **head);

//functions for Auguste
int		ft_clean_quit(t_score **head, int fd, char *line, int error);
int		check_pseudo_format(char *pseudo);
int		check_line_format(char *line);
int		add_line_to_score(char *line, t_score **head);
int		separate_pseudo_score(char *line) ;

#endif

/*
	file format:
[pseudo]:[value]\n

pseudo must be alphanum
value must be positive and < INT_MAX
*/
