/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_too_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:38:36 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 04:39:23 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void	ft_too_small(t_game *game)
{
	clear();
	ft_vertical_align(game, 1);
	ft_print_center(game, "TOO SMALL");
	refresh();
}