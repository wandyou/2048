#include "2048.h"
#include "board.h"
#include "board_movement.h"
#include "randomizer.h"
#include "check_board_status.h"

void handle_arrow(int direction, t_game *game)
{
	board_move(direction, game);
	if (game->board.has_changed)
	{
		generate_random_number_in_random_empty_tile(game);
		check_board_status(game);
	}
	// TODO : Check victory or defeat ?
}

void print_tile_background(t_game *game, t_tile *tile)
{
	for (int line = 0; line < game->board.tile_height; line++)
	{
		move(	tile->line_idx * (game->board.tile_height + 1) + 1 + game->board.board_offset + line, \
				tile->col_idx * (game->board.tile_width + 1) + 1);
		hline(' ', game->board.tile_width);
	}
}

void print_tile_value(t_game *game, t_tile *tile)
{
	char buff[11] = "";
	if (tile->value != 0)
	{
		if (ft_is_ascii_possible(game))
			ft_print_tile_ascii(game, tile);
		else
		{
			int margin_top = (game->board.tile_height - 1) / 2;
			int margin_left = (game->board.tile_width - ft_numlen(tile->value)) / 2 + 1;
			mvprintw(	tile->line_idx * game->board.tile_height + margin_top + 1 + game->board.board_offset + tile->line_idx, \
						tile->col_idx * (game->board.tile_width + 1) + margin_left, \
						ft_itoa(tile->value, buff));
		}
	}
}


int get_trailing_zeros_nb(int value)
{
	if (value > 2048)
		return (VALUE4096_PAIR);
	int ret = 1;
	while (value > 1)
	{
		value = value >> 1;
		ret++;
	}
	return ret;	
}

void print_tile_content(t_game *game, t_tile *tile)
{
	attron(COLOR_PAIR(get_trailing_zeros_nb(tile->value)));
	attron(A_BOLD);
	print_tile_background(game, tile);
	print_tile_value(game, tile);
	attroff(A_BOLD);
	attroff(COLOR_PAIR(tile->value));
}

void print_tiles_content(t_game *game)
{
	for (int line = 0; line < game->board.line_nb; line++)
	{
		for (int col = 0; col < game->board.col_nb; col++)
		{
			print_tile_content(game, &game->board.tiles[line][col]);
		}
	}
}

bool board_is_printable(t_game *game)
{
	return ((COLS > (ft_numlen(game->max_size_tile) + 3) * game->game_size + 1) \
			&& (LINES > (2 * game->game_size) + 1 + game->board.board_offset)); 
}

void print_metadata(t_game *game)
{
	attron(COLOR_PAIR(GLOBAL_PAIR));
	attron(A_BOLD);
	char buff[11] = "";
	ft_print_title((COLS - 16) / 2, 0);
	if (COLS < 60)
	{
		mvprintw(6, 2, "Player: %s", game->pseudo);
		mvprintw(7, 2, "Score: %s", ft_itoa(game->board.score, buff));
	}
	else
	{
		mvprintw(1, 2, "Player: %s", game->pseudo);
		mvprintw(2, 2, "Score: %s", ft_itoa(game->board.score, buff));
	}
	attroff(A_BOLD);
	attroff(COLOR_PAIR(GLOBAL_PAIR));
}

int	ft_game_loop(t_game *game)
{
	game->key = 0; // à retenir qu'il est pas init
	while(signal_global) {
		clear();
		update_board(game);

		if (game->key == ESC)
			break;

		switch (game->key)
		{
		case 410: // resize window
			break;
		case KEY_UP:
		case KEY_DOWN:
		case KEY_LEFT:
		case KEY_RIGHT:
			handle_arrow(game->key, game);
			break;
		default:
			// mvprintw(10, 1, "Character pressed is = %d Hopefully it can be printed as '%c'", c, c);
			break;
		}

		if (game->board.game_status == WIN || game->board.game_status == LOST)
			break;

		ft_get_max_size_tile(game);

		if (board_is_printable(game))
		{
			print_board(game);
			print_tiles_content(game);
			print_metadata(game);
		}
		else
		{
			mvprintw(LINES/2, (COLS / 2) - 4, "TOO SMALL");
		}

		// sprintf(msg, "Game status = %d", board.game_status);
		// mvprintw(1, 1, msg); // Message de debug temporaire	
		// sprintf(msg, "Tile_width = %d", board.tile_width);
		// mvprintw(1, 1, msg); // Message de debug temporaire	
		// sprintf(msg, "Tile_heigth = %d", board.tile_height);
		// mvprintw(2, 1, msg); // Message de debug temporaire	
		// sprintf(msg, "COLS = %d, LINES = %d", COLS, LINES);
		// mvprintw(3, 1, msg); // Message de debug temporaire
		// sprintf(msg, "board has changed ? %d", board.has_changed);
		// mvprintw(4, 1, msg); // Message de debug temporaire

		refresh();
		game->key = getch();
	}
	if (signal_global)
	{
		if (game->board.game_status == WIN)
			return ft_win_menu(game);
		else if (game->board.game_status == KEEP_PLAYING)
			return ft_win_menu(game);
		else if (game->board.game_status == LOST)
			return ft_lost_menu(game);
	}
	return (1);
}
