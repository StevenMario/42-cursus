/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:14:01 by mrambelo          #+#    #+#             */
/*   Updated: 2024/08/01 20:47:38 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine(void *arg)
{
	(void )arg;
	printf("Hello world\n");
	return NULL;
}

int ft_start(t_info **info)
{
	int	i;

	i = 0;
	(*info)->philosophe = malloc(sizeof(t_philo) * (*info)->nb_philo);
	while (i < (*info)->nb_philo)
	{
		if (pthread_create(&(*info)->philosophe[i].philo,NULL,&routine,NULL) != 0)
			return (0);
		i++;	
	}
	i = 0;
	while (i < (*info)->nb_philo)
	{
	if (pthread_join((*info)->philosophe[i].philo,NULL) != 0)
			return (0);
		i++;
	}
	return (1);	
}

int	main(int argc, char **argv)
{
	t_info *info;
	
	if (argc == 5 || argc == 6)
	{
		if (!check_arg(argv))
			printf("[Error].Please check the arguments!\n");
		else 
		{
			if (!init_all(argv,&info))
				return (1);
			ft_start(&info);
		}
	}
	else
	{
		printf("[Error].Please check the number of arguments!\n");
		return (1);
	}
}