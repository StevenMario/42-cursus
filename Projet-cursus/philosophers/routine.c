/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:16:12 by mrambelo          #+#    #+#             */
/*   Updated: 2024/08/06 13:13:47 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_take_fork(t_philo *philo, int l_fork, int r_fork)
{
	if (philo->id_philo % 2 == 0)
	{
		pthread_mutex_lock(&philo->info->fork[l_fork]);
		ft_printf_status(TAKE_FORK,philo);
		pthread_mutex_lock(&philo->info->fork[r_fork]);
		ft_printf_status(TAKE_FORK,philo);
	}
	else 
	{
		pthread_mutex_lock(&philo->info->fork[r_fork]);
		ft_printf_status(TAKE_FORK,philo);
		pthread_mutex_lock(&philo->info->fork[l_fork]);
		ft_printf_status(TAKE_FORK,philo);
	}
}

void	ft_eat(t_philo *philo)
{
	int	l_fork;
	int r_fork;

	l_fork = philo->id_philo - 1;
	r_fork = philo->id_philo % philo->info->nb_philo;
	ft_take_fork(philo,l_fork,r_fork);
	pthread_mutex_lock(&philo->info->eat_lock);
	philo->last_eat = ft_get_current_time();
	if (philo->info->nb_of_philo_must_eat >= 0)
		philo->nb_eat++;
	pthread_mutex_unlock(&philo->info->eat_lock);
	ft_printf_status(EAT,philo);
	ft_usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->info->fork[l_fork]);
	pthread_mutex_unlock(&philo->info->fork[r_fork]);
}

void	ft_sleep(t_philo *philo)
{
	ft_printf_status(SLEEP,philo);
	ft_usleep(philo->info->time_to_sleep);
}

void ft_think(t_philo *philo)
{
	ft_printf_status(THINK,philo);
}