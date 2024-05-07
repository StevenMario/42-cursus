/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:20:25 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/06 21:29:51 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_stack **a)
{
    t_stack *temp;
    t_stack *temp2;
    
    if (*a == NULL || (*a)->next == NULL) {
        return;
    }
    temp = (*a)->next;
    temp2 = temp->next;
    (*a)= temp;
    (*a)->next = temp;
    (*a)->prev = ft_lstlast((*a));
}

void swap_b(t_stack**b)
{
    
}
