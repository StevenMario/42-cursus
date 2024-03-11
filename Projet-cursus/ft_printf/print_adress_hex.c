/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:33:49 by mrambelo          #+#    #+#             */
/*   Updated: 2024/03/11 13:33:53 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_adress_hex(void *adress)
{
	int				i;
	unsigned long	nbr;	

	nbr = (unsigned long)adress;
	i = 0;
	i += print_str("0x");
	i += print_hex(nbr, 'x');
	return (i);
}
