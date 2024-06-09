/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:17:43 by mrambelo          #+#    #+#             */
/*   Updated: 2024/06/09 15:38:11 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int    main(void)
{
    int pid;
    
    pid = getpid();
    write(1,"Server PID: ",12);
    ft_putnbr_fd(pid,1);
    write(1,"\n",1);
}