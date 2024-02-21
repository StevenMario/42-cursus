/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:28:18 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/21 12:34:07 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int searchChar)
{
	int		i;
	char	letter;

	i = 0;
	letter = (char)searchChar;
	while (str[i] != '\0')
	{
		if (str[i] == letter)
			return ((char *)str + i);
		i++;
	}
	return ((char *) NULL);
}
