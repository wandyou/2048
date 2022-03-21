/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:25:20 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 04:33:41 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

int	ft_is_left_key(t_game *game)
{
	if (game->key == LEFT)
		return (1);
	else
		return (0);
}

int	ft_is_right_key(t_game *game)
{
	if (game->key == RIGHT)
		return (1);
	else
		return (0);
}

int	ft_is_up_key(t_game *game)
{
	if (game->key == UP)
		return (1);
	else
		return (0);
}

int	ft_is_down_key(t_game *game)
{
	if (game->key == DOWN)
		return (1);
	else
		return (0);
}

int	ft_is_enter_key(t_game *game)
{
	if (game->key == ENTER)
		return (1);
	else
		return (0);
}

int	ft_is_esc_key(t_game *game)
{
	if (game->key == ESC)
		return (1);
	else
		return (0);
}