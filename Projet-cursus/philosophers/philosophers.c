/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:14:01 by mrambelo          #+#    #+#             */
/*   Updated: 2024/08/06 13:43:12 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id_philo % 2 == 0)
		usleep(1000);
	while (!is_dead(philo))
	{
		ft_think(philo);
		if (philo->info->nb_philo != 1)
			ft_eat(philo);
		ft_sleep(philo);
		
	}
	return NULL;
}

void destroy_all_mutex(t_info **info)
{
	int i;

	i = 0;
	while (i < (*info)->nb_philo)
	{
		pthread_mutex_destroy(&(*info)->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&(*info)->eat_lock);
}

int ft_start(t_info **info)
{
	int	i;

	i = 0;
	(*info)->philosophe = malloc(sizeof(t_philo) * (*info)->nb_philo);
	(*info)->start_time = ft_get_current_time();
	while (i < (*info)->nb_philo)
	{
		(*info)->philosophe[i].id_philo = i + 1;
		(*info)->philosophe[i].info = (*info);
		(*info)->philosophe[i].nb_eat = 0;
		(*info)->philosophe[i].flag = 0;
		(*info)->philosophe[i].last_eat = (*info)->start_time;
		i++;
	}
	if (pthread_create(&(*info)->check_death,NULL,&check_death, *info) != 0)
			return (0);
	i = 0;
	while (i < (*info)->nb_philo)
	{
		if (pthread_create(&(*info)->philosophe[i].philo,NULL,&routine, &(*info)->philosophe[i]) != 0)
			return (0);
		i++;	
	}
	i = 0;
	if (pthread_join((*info)->check_death,NULL) != 0)
			return (0);
	while (i < (*info)->nb_philo)
	{
		if (pthread_join((*info)->philosophe[i].philo,NULL) != 0)
			return (0);
		i++;
	}
	destroy_all_mutex(info);
	free((*info)->fork);
	free((*info)->philosophe);
	free(*info);
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