#include <ncurses.h>
#include "board.h"

void update_board(t_game *game)
{
	game->board.tile_width = (COLS - game->board.col_nb - 1) / game->board.col_nb;
	game->board.tile_height = (LINES - game->board.line_nb - 1 - game->board.board_offset) / game->board.line_nb;
	if (COLS < 60)
		game->board.board_offset = 8;
	else
		game->board.board_offset = 6;
}

void print_board(t_game *game)
{
	for (int line = game->board.board_offset; line < game->board.line_nb * (game->board.tile_height + 1) + 1 + game->board.board_offset; line++)
	{
		for (int col = 0; col < game->board.col_nb * (game->board.tile_width + 1) + 1; col++)
		{
			if ((line - game->board.board_offset) % (game->board.tile_height + 1) == 0 || col % (game->board.tile_width + 1) == 0)
			{
				attron(COLOR_PAIR(BORDER_PAIR));
				mvaddch(line, col, ' ');
				attroff(COLOR_PAIR(BORDER_PAIR));
			}
		}
	}
}