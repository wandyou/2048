/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_title.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 08:40:33 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 08:42:34 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void	ft_print_title(int x, int y)
{
	ft_print_nb_ascii(2, x, y);
	ft_print_nb_ascii(0, x + 4, y);
	ft_print_nb_ascii(4, x + 8, y);
	ft_print_nb_ascii(8, x + 12, y);
}