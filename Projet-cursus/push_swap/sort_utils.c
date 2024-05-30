/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:33:38 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/30 15:59:56 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void prep_for_push(t_stack **stack, t_stack *top_stack, char stack_name)
{
	while ((*stack) != top_stack)
	{
		if (stack_name == 'a')
		{
			if (top_stack->above_median)
				rotate_a(stack);
			else
				reverse_rotate_a(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_stack->above_median)
				rotate_b(stack);
			else
				reverse_rotate_b(stack);
		}
	}
}

void min_on_top(t_stack **a)
{
	while ((*a)->nbr != find_smallest((*a))->nbr)
	{
		if (find_smallest((*a))->above_median)
			rotate_a(a);
		else 
			reverse_rotate_a(a);
	}
}

void set_index_and_median(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = stack_len(stack) / 2;
	while (stack != NULL)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else 
			stack->above_median = 0;
		stack = stack->next;	
		i++;
	}
}

void set_cheapest(t_stack *stack)
{
	long	best_match_value;
	t_stack	*best_match_node;

	if (stack == NULL)
		return ;
	best_match_value = 2147483647;
	while (stack != NULL)
	{
		if (stack->push_price < best_match_value)
		{
			best_match_value = stack->push_price;
			best_match_node = stack;
		}
		stack = stack->next;
	}
	best_match_node->cheapest = 1;
}

t_stack *get_cheapest(t_stack *stack)
{
	while(stack != NULL)
	{
		if (stack->cheapest == 1)
			break ;
		else
			stack = stack->next; 
	}
	return (stack);
}