/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:20:25 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/07 19:57:51 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **a)
{
    t_stack *temp;
    
    if (*a == NULL || (*a)->next == NULL) {
        return;
    }
    temp = (*a)->next;
    (*a)->next = temp->next;
    temp->next = (*a);
    if ((*a)->prev != NULL)
        (*a)->prev->next = temp;
    if (temp->prev!= NULL) {
        temp->prev->next = *a;
    }
    temp->prev = *a;
}
