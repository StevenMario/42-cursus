/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:17:32 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/15 11:22:56 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_to_server(int pid, char c)
{
	int	i;
	int	shift;

	i = 7;
	while (i >= 0)
	{
		shift = 1 << (i);
		if (c & shift)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i--;
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_to_server(pid, str[i]);
		i++;
	}
	signal(SIGUSR1, sighandler);
	send_to_server(pid, str[i]);
}

int	check_arg_and_send_message(char **str)
{
	int		pid;
	char	*message;

	pid = ft_atoi(str[1]);
	if (pid < 1 || check_pid(str[1]) == 0)
	{
		ft_printf("[Erreur]. Veillez verifier votre PID!\n");
		return (0);
	}
	message = str[2];
	if (message[0] == '\0')
	{
		ft_printf("[Erreur]. Aucun message n'a ete entrer!\n");
		return (0);
	}
	else
	{
		send_message(pid, message);
		return (1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (check_arg_and_send_message(argv) == 0)
			return (1);
	}
	else
	{
		ft_printf("[Erreur]. Veuillez verifier le nombre d'argument!\n");
		ft_printf("Entrer quelque chose comme:./client <PID> <MESSAGE>\n");
		return (1);
	}
	return (0);
}
