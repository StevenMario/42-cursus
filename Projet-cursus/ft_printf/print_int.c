/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:26:02 by mrambelo          #+#    #+#             */
/*   Updated: 2024/03/07 10:26:04 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int print_int(int nbr)
{
	int	len;
	char	*str;
	
	str = ft_itoa(nbr);
	print_str(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
