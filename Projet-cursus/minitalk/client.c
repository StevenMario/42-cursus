/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:17:32 by mrambelo          #+#    #+#             */
/*   Updated: 2024/06/13 09:05:25 by mrambelo         ###   ########.fr       */
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
	send_to_server(pid, str[i]);
}

int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_arg_and_send_message(char **str)
{
	int		pid;
	char	*message;

	pid = ft_atoi(str[1]);
	if (pid < 1 || check_pid(str[1]) == 0)
	{
		ft_printf("[Error]. Please check your PID!\n");
		return (0);
	}
	message = str[2];
	if (message[0] == '\0')
	{
		ft_printf("[Erreur]. No message has been entered!\n");
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
		else
			return (0);
	}
	else
	{
		ft_printf("[Error].Please check the number of arguments!\n");
		ft_printf("Enter something like this :./client <PID> <MESSAGE>\n");
		return (1);
	}
	return (0);
}
