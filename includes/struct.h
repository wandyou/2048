#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>

typedef struct s_score
{
	char * pseudo;
	int score;
	struct s_score *next;
}			t_score;

typedef struct s_tile {
	int value;
	int line_idx;
	int col_idx;
	bool is_merged;
} t_tile;

typedef enum e_game_status
{
	IN_GAME,
	LOST,
	WIN,
	KEEP_PLAYING
}			enum_game_status;

typedef struct s_board {
	int line_nb;
	int col_nb;
	int tile_nb;
	int tile_width;
	int tile_height;
	bool has_changed;
	int	score;
	bool is_printable;
	int board_offset;
	enum_game_status game_status;
	t_tile **tiles;
} t_board;

typedef struct s_game {
	t_board board;
	int		nb_char_lines;
	int		nb_char_cols;
	int		actual_cursor_line;
	int		key;
	int		selected_menu_pos;
	int		game_size;
	int		max_size_tile;
	t_score *scores;
	char	*pseudo;
} t_game;

#endif
