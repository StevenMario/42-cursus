/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:25:39 by mrambelo          #+#    #+#             */
/*   Updated: 2024/03/07 10:25:41 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_len(unsigned long long nbr)
{
	int	len;

	len = 0;
	while (len != 0)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}

static void	ft_putnbr_base_16(unsigned long long nbr, char *base)
{
	if (nbr >= 16)
	{
		ft_putnbr_base_16(nbr / 16, base);
		ft_putnbr_base_16(nbr % 16, base);
	}
	else
		ft_print_char(base[nbr]);
}

int	print_hex(unsigned long long nbr, char c)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_putnbr_base_16(nbr, base);
	return (nbr_len(nbr));
}
