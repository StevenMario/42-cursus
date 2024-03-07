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

int check_type(const char c, void  *arg)
{
	int	i;
	
	i = 0;
	if (c == 'c')
		i = i + ft_print_char((char)arg);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int	check;
	va_list	arg;
	
	check = 0;
	va_start(arg,format);
	while (format[i] != '\0')
	{
		if(format[i] == %)
		{
			format[i]++;
			if (format[i] == '\0')
				break;
			if (ft_strchr("cspdiuxX",format[i]))
				check += check_type(format[i],va_arg(arg, void *));
			else if (format[i] == '%')
				check += check + ft_print_char('%');
		}
		else
			check = check + ft_print_char(format[i]);
		i++;	
	}
	va_end(args);
	return (check);
}
