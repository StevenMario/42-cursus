/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_lstnew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:54:13 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/03 13:59:21 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_last_stack(t_list)
{
	
}

t_stack *ft_double_lstnew(t_stack **stack,int nbr)
{
	t_stack   *new_stack;
	t_stack 	*last_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack || !data)
		return (NULL);
	new_stack->prev= NULL;
	new_stack->data = data;
	new_stack->next= NULL;
	if (!stack)
		*stack = new_stack;
	else 
	{
		last_stack = find_last_stack(stack);
	}

	return (new_stack);
}