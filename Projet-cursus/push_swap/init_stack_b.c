/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:27:19 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/28 13:21:18 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// void set_price_b(t_stack *a, t_stack *b)
// {
// 	int	len_a;
// 	int	len_b;

// 	len_a = stack_len(&a);
// 	len_b = stack_len(&b);
// 	while (b)
// 	{
// 		b->push_price = b->index;
// 		if (!(b->above_median))
// 			b->push_price = len_b - (b->index);
// 		if (b->target_node->above_median)
// 			b->push_price += b->target_node->index;
// 		else
// 			b->push_price += len_a - (b->target_node->index);
// 		b = b->next;
		
// 	}
// }

void init_stack_b(t_stack *a, t_stack *b)
{
	set_index_and_median(a);
	set_index_and_median(b);
	set_target_node_b(a,b);
}