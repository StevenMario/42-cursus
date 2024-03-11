/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfriedri <tfriedri@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:36:17 by tfriedri          #+#    #+#             */
/*   Updated: 2022/04/08 18:06:04 by tfriedri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	print_str(char *str);
int	print_int(int nbr);
int	print_unsigned_dec(unsigned long int nbr);
int	print_hex(unsigned long long nbr, char c);
int	print_adress_hex(void *adress);

#endif
