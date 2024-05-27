/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:33:38 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/27 14:42:06 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_target_node_a(t_stack *a, t_stack *b)
{
	t_stack *current_b;
	t_stack *target_node;
	long		best_match_index;

	while (a)
	{
		best_match_index = -2147483648;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr 
			&& current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == -2147483648)
			target_node = find_smallest(b);
		else 
			a->target_node = target_node;
		a = a->next;
	}
}

void set_target_node_b(t_stack *a, t_stack *b)
{
	t_stack *current_a;
	t_stack *target_node;
	long		best_match_index;

	while (b)
	{
		best_match_index = 2147483647;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr 
			&& current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == 2147483647)
			target_node = find_smallest(a);
		else 
			b->target_node = target_node;
		b = b->next;
	}
}

void set_index_and_median(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = stack_len(&stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else 
			stack->above_median = 0;
		i++;
	}
}

void set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(&a);
	len_b = stack_len(&b);
	while (b)
	{
		b->push_price = b->index;
		if (!(b->above_median))
			b->push_price = len_b - (b->index);
		if (b->target_node->above_median)
			b->push_price += b->target_node->index;
		else
			b->push_price += len_a - (b->target_node->index);
		b = b->next;
		
	}
}

void set_cheapest(t_stack *b)
{
	long	best_match_value;
	t_stack	*best_match_node;

	if (b == NULL)
		return ;
	best_match_value = 2147483647;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = 1;
}