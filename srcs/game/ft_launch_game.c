/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaure <afaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:57:53 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 18:08:53 by afaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"
#include "board.h"
#include "randomizer.h" 



int	ft_launch_game(t_game *game)
{
	clear();
	if (!ft_init_board(game))
		return (0);

	generate_random_number_in_random_empty_tile(game);
	generate_random_number_in_random_empty_tile(game);

	return ft_game_loop(game); // Le mettre dans une fonction séparée permet de relancer la loop sans ecraser la partie en cours
}
