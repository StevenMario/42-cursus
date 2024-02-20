/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 07:38:43 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/20 08:30:09 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*destination;
	const char		*source;

	i = 0;
	source = (const char *)src;
	destination = (char *)dest;
	if (dest && src)
	{
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (destination);
}
