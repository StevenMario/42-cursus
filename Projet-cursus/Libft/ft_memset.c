/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:30:28 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/19 14:50:11 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	int	i;
	unsigned	char
		*str;

	str = (unsigned char *)pointer;
	i = 0;
	while (i <= count)
	{
		str[i] = (unsigned char)value;
		i++;
	}
	return (pointer);
}
