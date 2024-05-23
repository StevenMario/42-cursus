/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:12:39 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/23 21:22:02 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*next;

	if (!(*lst) || !(*lst)->next)
		return (0);
	temp = (*lst);
	while (temp && temp->next)
	{
		next = temp->next;
		if (temp->nbr > next->nbr)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_three(t_stack **lst)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = (*lst);
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
