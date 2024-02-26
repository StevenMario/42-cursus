/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:00:36 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/26 16:00:39 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.c"

void	ft_putnbr_fd(int n, int fd)
{

	if (nb == -2147483648)
	{
		ft_putchar('-',fd);
		ft_putchar('2'),fd;
		ft_putnbr(147483648,fd);
	}
	else if (nb < 0)
	{
		ft_putchar('-',fd);
		nb = -nb;
		ft_putnbr(nb,fd);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10,fd);
		ft_putnbr(nb % 10,fd);
	}
	else
		ft_putchar(nb + '0',fd);
}
