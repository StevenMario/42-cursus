/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:21:36 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/30 14:11:33 by mrambelo         ###   ########.fr       */
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
			a->target_node = find_smallest(b);
		else 
			a->target_node = target_node;
		a = a->next;
	}
}

void set_price_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_price = a->index;
		if (!(a->above_median))
			a->push_price = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_price += a->target_node->index;
		else 
			a->push_price += len_b - (a->target_node->index);
		// printf("Nmobre = %d cible = %d prix = %d median = %d\n",a->nbr,a->target_node->nbr,a->push_price,a->above_median);
		a = a->next;
	}
}

void init_stack_a(t_stack *a, t_stack *b)
{
	set_index_and_median(a);
	set_index_and_median(b);
	set_target_node_a(a,b);
	set_price_a(a,b);
	set_cheapest(a);
}