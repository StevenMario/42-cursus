/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:48:38 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/15 20:58:11 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rotate_a_b(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
