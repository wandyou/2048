/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaure <afaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 00:05:16 by afaure            #+#    #+#             */
/*   Updated: 2021/08/17 00:36:00 by afaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	size;

	size = ft_strlen(s);
	ret = malloc((size + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s, size + 1);
	return (ret);
}
