/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:17:38 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/21 13:17:42 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int searchChar)
{
	int		i;
	char	letter;

	i = ft_strlen(str);
	i--;
	letter = (char)searchChar;
	while (str[i] != '\0')
	{
		if (str[i] == letter)
			return ((char *)str + i);
		i--;
	}
	return ((char *) NULL);
}
