/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:17:32 by mrambelo          #+#    #+#             */
/*   Updated: 2024/06/09 15:36:24 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_to_server(int pid, char c)
{
		int i ;
		int shift;

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
void send_message(int pid,char *str)
{
	int i;
	i = 0;

	while (str[i] != '\0')
	{
		send_to_server(pid, str[i]);
		i++;
	}
	send_to_server(pid, str[i]);
}

int main(int argc , char **argv)
{
	int pid;
	char *message;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 1)
		{
			write(1,"[Erreur]. Veillez verifier votre PID!",37);
			write(1,"\n",1);
			return (1);
		}
		message = argv[2];
		if (message[0] == '\0')
		{
			write(1,"[Erreur]. Aucun message n'a ete entrer!",39);
			write(1,"\n",1);
			return (1);
		}
		else
			send_message(pid,message);
	}	
	else
	{
		write(1,"[Erreur]. Veuillez verifier le nombre d'argument!",49);
		write(1,"\n",1);
		write(1,"Vous devez entrer quelque chose comme ceci :./client <PID> <MESSAGE>",68);
		write(1,"\n",1);
		return (1);
	}
	return 0;
}
