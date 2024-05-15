/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:41:34 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/15 12:07:49 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void swap_b(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void swap_a_b(t_stack **a,t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}