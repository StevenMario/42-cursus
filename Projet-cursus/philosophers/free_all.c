/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:08:16 by mariosteven       #+#    #+#             */
/*   Updated: 2024/08/12 20:37:22 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void free_all(t_info **info)
{
	destroy_all_mutex(info);
	free((*info)->fork);
	free((*info)->philosophe);
	free(*info);
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
	pthread_mutex_destroy(&(*info)->mutex);
}