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
#include "libft.h"

int check_type(const char *c, void * arg)
{
	int	i;
	
	i = 0;
	if (*c == 's')
		i = i + print_str((char *)arg);
	/*else if (c == 'p')
		i = i + print_hex((void *)arg)*/
	else if (*c == 'd' || *c == 'i')
		i = i + print_int((intptr_t)arg);
	/*else if (c == 'u')
		i = i + print_unsigned_dec((unsigned long)arg);
	else if (c == 'x')
		i = i + print_hex_min((unsigned int)arg);
	else if (c == 'x')
		i = i + print_hex_maj((unsigned int)arg);*/
	return i;
}

int	ft_printf(const char *format, ...)
{
	int	check;
	va_list	arg;
	
	check = 0;
	va_start(arg,format);
	while (*format != '\0')
	{
		if(*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
				check = check + ft_print_char(va_arg(arg, int));
			if (ft_strchr("spdiuxX",*format))
				check += check_type(format,va_arg(arg, void *));
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
int main()
{
	ft_printf("ceci et %d \n", 234);
	return 0;
}
