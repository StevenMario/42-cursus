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

int	check_type(const char *c, va_list arg)
{
	int	i;

	i = 0;
	if (*c == 'c')
		i = i + ft_print_char(va_arg(arg, int));
	else if (*c == 's')
		i = i + print_str(va_arg(arg, char *));
	else if (*c == 'p')
		i = i + print_adress_hex(va_arg(arg, void *));
	else if (*c == 'd' || *c == 'i')
		i = i + print_int(va_arg(arg, int));
	else if (*c == 'u')
		i = i + print_unsigned_dec(va_arg(arg, unsigned long int));
	else if (*c == 'X' || *c == 'x')
		i = i + print_hex(va_arg(arg, unsigned long long), *c);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		check;
	va_list	arg;

	check = 0;
	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			if (ft_strchr("cspdiuxX",*format))
				check += check_type(format, arg);
			if (*format == '%')
				check += check + ft_print_char('%');
		}
		else
			check = check + ft_print_char(*format);
		format++;
	}
	va_end(arg);
	return (check);
}
