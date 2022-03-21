/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_max_size_tile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 07:13:27 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 07:21:05 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void	ft_get_max_size_tile(t_game *game)
{
	game->max_size_tile = 0;
	for (int y = 0; y < game->board.line_nb; y++)
	{
		for (int x = 0; x < game->board.col_nb; x++)
		{
			if (game->board.tiles[y][x].value > game->max_size_tile)
				game->max_size_tile = game->board.tiles[y][x].value;
		}
	}
}