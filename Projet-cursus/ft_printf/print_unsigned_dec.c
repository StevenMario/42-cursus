/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:22:10 by mrambelo          #+#    #+#             */
/*   Updated: 2024/03/09 08:22:13 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	nbr_number(int n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_unsigned_itoa(int n)
{
	char		*str_num;
	size_t		digits;
	long int	num;

	num = n;
	digits = nbr_number(n);
	str_num = (char *)malloc(sizeof(char) * (digits + 1));
	if (!(str_num))
		return (NULL);
	*(str_num + digits) = '\0';
	while (digits--)
	{
		*(str_num + digits) = num % 10 + '0';
		num = num / 10;
	}
	return (str_num);
}

int	print_unsigned_dec(unsigned long int nbr)
{
	size_t	len;
	char	*str;

	if (nbr == 0)
	{
		ft_print_char('0');
		return (1);
	}
	else
	{
		str = ft_unsigned_itoa(nbr);
		print_str(str);
	}
	len = ft_strlen(str);
	return (len);
}
