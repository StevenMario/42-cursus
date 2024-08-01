/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:56:46 by mariosteven       #+#    #+#             */
/*   Updated: 2024/08/01 12:57:16 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_struct(char **argv,t_info **info)
{
	*info = malloc(sizeof(t_info));
	if (!*info)
		return (0);
	(*info)->nb_philo = ft_atoi(argv[1]);
	(*info)->time_to_die = ft_atol(argv[2]);
	(*info)->time_to_eat = ft_atol(argv[3]);
	(*info)->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		(*info)->nb_of_philo_msut_eat = ft_atoi(argv[5]);
	(*info)->status = 0;
	return (1);
}

int init_fork_mutex(t_info **info)
{
	int i;
	int error;
	
	i = 0;
	(*info)->fork = malloc(sizeof(pthread_mutex_t) * (*info)->nb_philo);
	if (!(*info)->fork)
		return (0);
	while (i < (*info)->nb_philo)
	{
		error = pthread_mutex_init(&(*info)->fork[i],NULL);
		if (error != 0 && i - 1 >= 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&(*info)->fork[i]);
			return (0);
		}
		i++;
	}
	return 1;
}

int init_other_mutex(t_info **info)
{
	if (pthread_mutex_init(&(*info)->print_lock,NULL))
		return (0);
	if (pthread_mutex_init(&(*info)->dead_lock,NULL))
	{
		pthread_mutex_destroy(&(*info)->print_lock);
		return (0);
	}
	return (1);
}

int init_all(char **argv,t_info **info)
{
	if (!init_struct(argv,info))
	{
		free(info);
		printf("Allocation error!\n");
		return (0);
	}
	if (!init_fork_mutex(info))
	{
		free(info);
		printf("Mutex error !\n");
		return (0);
	}
	if (!init_other_mutex(info))
	{
		free(info);
		printf("Mutex error !\n");
		return (0);
	}
	return (1);
}