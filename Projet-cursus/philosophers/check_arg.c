/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:35:12 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/25 12:37:52 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	check_arg(char **argv)
{
	int	i;

	i = 1;
	while(argv[i])
	{
		if (!is_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}