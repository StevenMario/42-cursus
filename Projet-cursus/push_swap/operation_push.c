/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:46:31 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/15 20:59:18 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	push_b(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_printf("pb\n");
}
