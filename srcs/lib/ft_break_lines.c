/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_break_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:34:21 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 04:32:52 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void	ft_break_lines(t_game *game, int nb_breaks)
{
	while (nb_breaks > 0)
	{
		ft_break_line(game);
		nb_breaks--;
	}
}