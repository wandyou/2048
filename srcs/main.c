#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include "struct.h"
#include "board.h"
#include "randomizer.h"
#include "board_movement.h"
#include "check_board_status.h"
#include "2048.h"
#include "file_scoring.h"


int signal_global;
// Test movement with gcc main.c board.c ft_calloc.c randomizer.c board_movement.c vector_conversions.c -lncurses -o test && ./test

int free_all(t_game *game, int error)
{
	if (game->board.tiles)
	{
		for(int y = 0; y < game->game_size; y++)
		{
			if (game->board.tiles[y])
				free(game->board.tiles[y]);
		}
		free(game->board.tiles);
	}
	if (!error)
		put_score_to_file(game->scores, game->pseudo);
	nocbreak();
	curs_set(1);
	endwin();
	destroy_list(&game->scores);
	return (0);
}

int main(int argc, char **argv)
{
	int ret;
	t_game game;
	ft_memset(&game, '\0', sizeof(t_game));

	if (argc < 2)
		game.pseudo = "AUTONA";
	else if (argc > 2)
	{
		write(1, "Usage : ./2048 [pseudo]\n", 24);
		return (1);
	}
	else
	{
		if (check_pseudo_format(argv[1]))
			game.pseudo = argv[1];
		else
		{
			write(1, "Wrong pseudo format, only 20 alphanum chars\n", 44);
			return (1);
		}
	}

	if ((ret = ft_init(&game)) != SUCCESS) // Init everything
	{
		// print_err_msg(ret); // TODO THIS FUNCTION
		if (ret != ERROR_FD)
			return (free_all(&game, 1));
	}
	ft_start_menu(&game); // Launch the start menu
	free_all(&game, 0);
    return 0;
}
