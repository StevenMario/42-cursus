/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:33:38 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/24 11:10:30 by mrambelo         ###   ########.fr       */
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