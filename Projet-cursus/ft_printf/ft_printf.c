/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steven <steven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:50:40 by mrambelo          #+#    #+#             */
/*   Updated: 2024/03/05 10:17:35 by steven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int	ft_printf(const char *format, ...)
{
	int		i;
	unsigned int	check;
	va_list	args;
	
	va_start(args,format);
	while (format[i] != '\0')
	{
		if(format[i] == %)
		{
			format[i]++;
			if (ft_strchr("cspdiuxX",format[i]))
			{
				check += 
			}
		}
		else
			ft_print_char(format[i]);
		i++;	
	}
	va_end(args);
	return (check);
}
