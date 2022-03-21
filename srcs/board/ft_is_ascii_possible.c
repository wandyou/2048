/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_ascii_possible.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 07:21:27 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 14:08:39 by tokino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

int	ft_is_ascii_possible(t_game *game)
{
	int required_width = 4 * ft_numlen(game->max_size_tile) - 1;
	int required_height = 5;

	if (game->board.tile_width 	>= required_width && game->board.tile_height >= required_height)
		return (1);
	else
		return (0);
}