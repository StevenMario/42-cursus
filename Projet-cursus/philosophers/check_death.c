/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:20:50 by mrambelo          #+#    #+#             */
/*   Updated: 2024/08/07 10:49:00 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->eat_lock);
	if (philo->info->status == 1)
		return (pthread_mutex_unlock(&philo->info->eat_lock), 1);
	pthread_mutex_unlock(&philo->info->eat_lock);
	return (0);
}

int	check_if_all_eat(t_info *info,int *i)
{
	if (info->nb_of_philo_must_eat >= 0)
	{
		if (info->philosophe[*i].nb_eat == info->nb_of_philo_must_eat
		&& !info->philosophe[*i].flag )
		{
			info->philosophe[*i].flag = 1;
			info->all_eat++;
		}
		if (info->all_eat == info->nb_philo)
			return (1);
	}
	return (0);
}

void *check_death(void *arg)
{
	t_info	*info;
	int i;
	long current_time;
	info = (t_info *)arg;
	
	while (info->status == 0)
	{
		i = 0;
		current_time =  ft_get_current_time() - info->start_time;
		while (i < info->nb_philo)
		{
			pthread_mutex_lock(&info->eat_lock);
			if (check_if_all_eat(info,&i))
			{
				info->status = 1;
				pthread_mutex_unlock(&info->eat_lock);
				break;
			}
			pthread_mutex_unlock(&info->eat_lock);
			pthread_mutex_lock(&info->eat_lock);
			if (ft_get_current_time() - info->philosophe[i].last_eat > info->time_to_die)
			{
				info->status = 1;
				printf("\033[38;5;196m%ld  %d is died\n",current_time, info->philosophe[i].id_philo);
				pthread_mutex_unlock(&info->eat_lock);
				break ;
			}
			pthread_mutex_unlock(&info->eat_lock);
			i++;
		}
		usleep(100);
	}
	return NULL;
}