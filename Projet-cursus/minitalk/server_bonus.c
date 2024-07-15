/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:28:11 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/15 11:31:29 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	stock_char(char c, pid_t pid)
{
	static char	*str;
	char		tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	if (c == '\0')
	{
		ft_printf("%s\n", str);
		kill(pid, SIGUSR1);
		free(str);
		str = NULL;
	}
	else
	{
		if (str == NULL)
			str = ft_strdup("");
		str = ft_strjoin(str, tmp);
	}
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;

	(void)context;
	if (signum == SIGUSR1)
		c |= 1 << (7 - i);
	i++;
	if (i > 7)
	{
		stock_char(c, info->si_pid);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	ft_printf("#==================================================#\n");
	ft_printf("        Welcome to mrambelo's mintalk server        \n");
	ft_printf("        Server PID :  %d    \n", getpid());
	ft_printf("#==================================================#\n");
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
	}
}
