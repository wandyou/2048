#include "randomizer.h"

static int _get_empty_tile_nb(t_game *game)
{
	int empty_tile_nb = 0;

	for (int line = 0; line < game->board.line_nb; line++)
	{
		for (int col = 0; col < game->board.col_nb; col++)
		{
			if (game->board.tiles[line][col].value == 0)
				empty_tile_nb++;
		}
	}
	return empty_tile_nb;
}

static t_tile *_get_tile_to_fill(t_game *game, int rand_nb)
{
	t_tile *tile_to_fill = NULL;
	
	for (int line = 0; line < game->board.line_nb; line++)
	{
		for (int col = 0; col < game->board.col_nb; col++)
		{
			if (game->board.tiles[line][col].value == 0 && rand_nb >= 0)
			{
				tile_to_fill = &game->board.tiles[line][col];
				rand_nb--;
			}
		}
	}
	return tile_to_fill;
}

static int _generate_random_valid_number(void)
{
	// valid number is either 2 or 4. 2 must appear more often than 4.
	int rand_value = 5 * ((double)rand())/RAND_MAX; // Generate either 0, 1, 2, 3, or 4
	if (rand_value < 4) // In theorie, this give four 2 to one 4. To adjust.
		rand_value = 2;
	return rand_value;
}

void generate_random_number_in_random_empty_tile(t_game *game)
{
	int empty_tile_nb = _get_empty_tile_nb(game);
	if (empty_tile_nb == 0)
		return ;
	int rand_nb = empty_tile_nb * ((double)rand())/RAND_MAX;
	t_tile *tile_to_fill = _get_tile_to_fill(game, rand_nb);
	if (tile_to_fill == NULL)
		return ;
	tile_to_fill->value = _generate_random_valid_number();
}
