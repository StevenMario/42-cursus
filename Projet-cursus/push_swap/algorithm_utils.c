/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:12:39 by mariosteven       #+#    #+#             */
/*   Updated: 2024/06/03 09:49:21 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*next;

	if (!(*lst))
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

int	stack_len(t_stack *lst)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = lst;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest;
	t_stack	*current;

	smallest = stack;
	current = stack->next;
	while (current != NULL)
	{
		if (smallest->nbr > current->nbr)
			smallest = current;
		else
			current = current->next;
	}
	return (smallest);
}

t_stack	*find_biggest(t_stack *stack)
{
	long	max;
	t_stack	*big;

	if (!stack)
		return (NULL);
	max = -2147483648;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			big = stack;
		}
		stack = stack->next;
	}
	return (big);
}
