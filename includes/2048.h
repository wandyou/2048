/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaure <afaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:29:42 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 16:39:50 by afaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEUX_MILLE_QUARANTE_HUIT
# define DEUX_MILLE_QUARANTE_HUIT

// # include <stdio.h>, pas besoin de l'inclure, elle l'est implicitement par ncurses.h
# include <ncurses.h>
# include <stdlib.h>
# include <signal.h>
# include "libft.h"
# include "struct.h"
# include "file_scoring.h"

# define ESC 27
# define UP 259
# define DOWN 258
# define LEFT 260
# define RIGHT 261
# define ENTER 10

extern int signal_global;
/*
	MENUS
*/
int		ft_start_menu(t_game *game);
int		ft_size_menu(t_game *game);
int		ft_select_menu(int move, int current_pos, int menu_size);

/*
	CORE
*/
int		ft_is_left_key(t_game *game);
int		ft_is_right_key(t_game *game);
int		ft_is_up_key(t_game *game);
int		ft_is_down_key(t_game *game);
int		ft_is_enter_key(t_game *game);
int		ft_is_esc_key(t_game *game);

/*
	GAME
*/
int	ft_launch_game(t_game *game);

/*
	LEADERBOARD
*/
int	ft_leaderboard(t_game *game);

/*
	LIB
*/
void	ft_debug(t_game *game);
int		ft_init_struct(t_game *game);
void	ft_get_win_size(t_game *game);
void	ft_break_line(t_game *game);
void	ft_break_lines(t_game *game, int nb_breaks);
void	ft_clear(t_game *game);
void	ft_vertical_align(t_game *game, int element_height);
void	ft_print_center(t_game *game, char *str);
void	print_menu(t_game *game);
int		ft_is_ascii_possible(t_game *game);
void	ft_print_tile_ascii(t_game *game, t_tile *tile);
int	ft_init(t_game *game);
void	ft_get_max_size_tile(t_game *game);
int	ft_win_menu(t_game *game);
int	ft_lost_menu(t_game *game);
int	ft_game_loop(t_game *game);
void	ft_too_small(t_game *game);
void	ft_print_title(int x, int y);
void	ft_print_nb_ascii(int nb, int x, int y);

// OTHERS
void signal_handler(int signum);

#endif
