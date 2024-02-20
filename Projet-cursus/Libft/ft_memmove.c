/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:39:41 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/20 11:23:04 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char			*csrc;
	size_t		i;

	cdest = (char *)dest;
	csrc = (const char *)src;
	if (csrc == cdest || n == 0)
		return (dest);
	if (csrc < cdest && csrc + n > cdest)
	{
		i = n;
		while (i > 0)
		{
			i--;
			cdest[i] = csrc[i];
		}
	}
	else if (csrc > cdest && csrc < cdest + n)
	{
		i = 0;
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	else
	{
		memcpy(dest, src, n);
	}
	return (dest);
}
