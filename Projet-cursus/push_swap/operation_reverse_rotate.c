/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:51:32 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/28 13:26:06 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	reverse_rotate_a_b(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}

void reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while ((*a) != cheapest && (*b) != cheapest->target_node)
		reverse_rotate_a_b(a, b);
	set_index_and_median((*a));
	set_index_and_median((*b));
}
