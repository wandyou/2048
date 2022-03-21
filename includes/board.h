#ifndef BOARD_H
#define BOARD_H

#include "libft.h"
#include <stdbool.h>
#include "struct.h"

#define GLOBAL_PAIR		99
#define BORDER_PAIR		100
#define VALUE0_PAIR		1
#define VALUE2_PAIR		2
#define VALUE4_PAIR		3
#define VALUE8_PAIR		4
#define VALUE16_PAIR	5
#define VALUE32_PAIR	6
#define VALUE64_PAIR	7
#define VALUE128_PAIR	8
#define VALUE256_PAIR	9
#define VALUE512_PAIR	10
#define VALUE1024_PAIR	11
#define VALUE2048_PAIR	12
#define VALUE4096_PAIR	13

int ft_init_board(t_game *game);
void update_board(t_game *game);
void print_board(t_game *game);

#endif
