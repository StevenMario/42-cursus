/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:20:50 by mrambelo          #+#    #+#             */
/*   Updated: 2024/08/15 20:36:48 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->eat_lock);
	if (philo->info->status == 1)
		return (pthread_mutex_unlock(&philo->info->eat_lock), 1);
	pthread_mutex_unlock(&philo->info->eat_lock);
	return (0);
}

int	check_if_all_eat(t_info *info, int *i)
{
	if (info->nb_of_philo_must_eat >= 0)
	{
		if (info->philosophe[*i].nb_eat == info->nb_of_philo_must_eat
			&& !info->philosophe[*i].flag)
		{
			info->philosophe[*i].flag = 1;
			info->all_eat++;
		}
		if (info->all_eat == info->nb_philo)
			return (1);
	}
	return (0);
}

int	is_dead_or_all_eat(t_info *info, int *i, long current_time)
{
	pthread_mutex_lock(&info->eat_lock);
	if (check_if_all_eat(info, i))
	{
		info->status = 1;
		pthread_mutex_unlock(&info->eat_lock);
		return (0);
	}
	pthread_mutex_unlock(&info->eat_lock);
	pthread_mutex_lock(&info->eat_lock);
	if (ft_get_current_time() - info->philosophe[*i].last_eat
		> info->time_to_die)
	{
		info->status = 1;
		printf("\033[38;5;196m%ld  %d is died\n",
			current_time, info->philosophe[*i].id_philo);
		pthread_mutex_unlock(&info->eat_lock);
		return (0);
	}
	pthread_mutex_unlock(&info->eat_lock);
	return (1);
}

void	*check_death(void *arg)
{
	int		i;
	long	current_time;
	t_info	*info;

	info = (t_info *)arg;
	while (info->status == 0)
	{
		i = 0;
		pthread_mutex_lock(&info->mutex);
		current_time = ft_get_current_time() - info->start_time;
		pthread_mutex_unlock(&info->mutex);
		while (i < info->nb_philo)
		{
			if (!is_dead_or_all_eat(info, &i, current_time))
				break ;
			i++;
		}
		usleep(100);
	}
	return (NULL);
}
