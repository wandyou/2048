/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leaderboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaure <afaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:04:00 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 19:22:51 by afaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"
#include "file_scoring.h"

int	ft_leaderboard(t_game *game)
{
	int	i;
	char buff_itoa[30] = ""; // j'ai fait une fonction itoa custom pour ne plus avoir de malloc

	t_score *scores = game->scores;

	char *menu[] = {
		" BACK "
	};
	int menu_size = sizeof(menu) / sizeof(char *);
	int menu_height = 15 + menu_size;
	int menu_width = 13;

	size_t max_length = 0;

	game->key = 0;
	game->selected_menu_pos = 0;
	
	while (signal_global)
	{
		i = 0;
		ft_clear(game); // My own clear function to also clear other variables (like cursor position)
		ft_get_win_size(game);

		/*
			MENU LOGIC
		*/
		if (ft_is_esc_key(game))
		{
			game->selected_menu_pos = -1;
			break;
		}
		else if (ft_is_enter_key(game))
			break;

		if (game->nb_char_cols < menu_width || game->nb_char_lines < menu_height)
			ft_too_small(game);
		else
		{
			// Actually print the menu
			ft_vertical_align(game, menu_height);
			ft_print_title((game->nb_char_cols - (4 * 4)) / 2, game->actual_cursor_line);
			game->actual_cursor_line += 5;
			ft_break_lines(game, 2);
			t_score *tmpscores = scores;
			while (tmpscores)
			{
				size_t tmp = ft_strlen(tmpscores->pseudo) + ft_strlen(ft_itoa(tmpscores->score, buff_itoa));
				if (tmp > max_length)
					max_length = tmp;
				tmpscores = tmpscores->next;
			}

			printw("\n\n");
			while(scores)
			{
				for (int x = 0; x < ((game->nb_char_cols - (int)max_length) / 2 - 3); x++)
					printw(" ");
				printw("%s ", scores->pseudo);
				for (int x = -1; x < ((int)max_length - (int)ft_strlen(scores->pseudo) - (int)ft_strlen(ft_itoa(scores->score, buff_itoa))); x++)
					printw("-");
				printw(" ");
				printw("%d\n", scores->score);
				ft_break_line(game);
				scores = scores->next;
			}
			for (i = 0; i < menu_size; i++)
			{
				ft_break_line(game);
				attron(A_REVERSE);
				ft_print_center(game, menu[i]);
				attroff(A_REVERSE);
			}
		}

		refresh();
		game->key = getch();
	}

	destroy_list(&scores);
	if (game->selected_menu_pos == 0) // Back
		return ft_start_menu(game);
	return 1;
}
