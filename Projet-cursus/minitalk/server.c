/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:17:43 by mrambelo          #+#    #+#             */
/*   Updated: 2024/06/13 09:11:05 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	stock_char(char c)
{
	static char		*str;
	char			tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	if (str == NULL)
		str = ft_strdup("");
	str = ft_strjoin(str, tmp);
	if (c == '\0')
	{
		ft_printf("%s\n", str);
		free(str);
		str = NULL;
	}
}

void	signal_handler(int signum)
{
	static int	i;
	static char	c;

	if (signum == SIGUSR1)
		c |= 1 << (7 - i);
	i++;
	if (i > 7)
	{
		stock_char(c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("#==================================================#\n");
	ft_printf("        Welcome to mrambelo's mintalk server        \n");
	ft_printf("        Server PID :  %d    \n", getpid());
	ft_printf("#==================================================#\n");
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
	}
}
