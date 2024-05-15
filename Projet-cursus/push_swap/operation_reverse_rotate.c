/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:51:32 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/15 20:58:39 by mariosteven      ###   ########.fr       */
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
