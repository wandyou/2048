#include "check_board_status.h"

int check_win(t_game *game, long win_val)
{
	for(int y = 0; y < game->board.line_nb; y++)
	{
		for(int x = 0; x < game->board.col_nb; x++)
		{
			if (game->board.tiles[y][x].value == win_val)
				return (1);
		}
	}
	return (0);
}

//fonction qui va checker le carré en dessous et à droite 
//de chaque carré pour voir si il y a au moins deux carrés égaux
int check_lost(t_game *game)
{
	for(int line = 0; line < game->board.line_nb; line++)
	{
		for(int col = 0; col < game->board.col_nb; col++)
		{
			if (game->board.tiles[line][col].value == 0)
				return (0);
			if (line < game->board.line_nb - 1 && game->board.tiles[line][col].value == game->board.tiles[line + 1][col].value)
				return (0);
			if (col < game->board.col_nb - 1 && game->board.tiles[line][col].value == game->board.tiles[line][col + 1].value)
				return (0);
		}
	}
	return (1);
}

void check_board_status(t_game *game)
{
	long win_val;

	enum e_const
	{
		WIN_VALUE = 2048
	};

	if (WIN_VALUE != 0 && (WIN_VALUE & (WIN_VALUE - 1)) == 0)
		win_val = WIN_VALUE;
	else
		win_val = DEFAULT_WIN;

	if (game->board.game_status != KEEP_PLAYING && check_win(game, win_val))
		game->board.game_status = WIN;
	else if (check_lost(game))
		game->board.game_status = LOST;
}
