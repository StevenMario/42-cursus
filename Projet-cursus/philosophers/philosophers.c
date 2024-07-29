/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:14:01 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/29 20:45:10 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_struct(char **argv,t_philo **philo)
{
	
	*philo = malloc(sizeof(t_philo));
	if (!*philo)
		return (0);
	(*philo)->info = malloc(sizeof(t_info));
	if (!(*philo)->info)
		return (0);
	(*philo)->info->nb_philo = ft_atoi(argv[1]);
	(*philo)->info->time_to_die = ft_atol(argv[2]);
	(*philo)->info->time_to_eat = ft_atol(argv[3]);
	(*philo)->info->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		(*philo)->info->nb_of_philo_msut_eat = ft_atoi(argv[5]);
	return (1);
}

int	creat_pthread(t_philo *philo)
{
	int	i;
	
	i = 0;
	while (i < philo->info->nb_philo)
	{
		pthread_create(&philo->philo,NULL,&routine,NULL);
	}
}

int	main(int argc, char **argv)
{
	t_philo *philo;
	
	if (argc == 5 || argc == 6)
	{
		if (!check_arg(argv))
			printf("[Error].Please check the arguments!\n");
		else 
		{
			init_struct(argv,&philo);
			creat_pthread(philo);
		}
	}
	else
	{
		printf("[Error].Please check the number of arguments!\n");
		return (1);
	}
}