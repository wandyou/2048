/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tile_ascii.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 07:37:15 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 17:16:37 by tokino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void	ft_print_tile_ascii(t_game *game, t_tile *tile)
{
	int size = ft_numlen(tile->value);
	int width = size * 4 - 1;
	int height = 5;
	int margin_top = (game->board.tile_height - height) / 2;
	int margin_left = (game->board.tile_width - width) / 2;
	int nb = 0;
	int value = tile->value;
	
	for (int i = 0; i < size; i++)
	{
		nb = value % 10;
		value = value / 10;
		ft_print_nb_ascii(nb, \
			((tile->col_idx + 1) * game->board.tile_width) - (margin_left + ((i + 1) * 3)) - (1 * i) + (tile->col_idx + 1), \
			((tile->line_idx * game->board.tile_height) + margin_top) + (1 + tile->line_idx) + game->board.board_offset \
		);
	}
}