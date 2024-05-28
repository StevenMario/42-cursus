/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:23:38 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/28 13:30:04 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack *cheapest_stack;

	cheapest_stack = get_cheapest(*a);
	if (cheapest_stack->above_median && cheapest_stack->target_node->above_median)
		rotate_both(a,b,cheapest_stack);
	else if (!(cheapest_stack->above_median) && !(cheapest_stack->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_stack);
	prep_for_push((*a), cheapest_stack, 'a');
	prep_for_push((*b), cheapest_stack->target_node, 'b');
	push_b(b,a);
}
void move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push((*a), (*b)->target_node,'a');
	push_a(a,b);
}