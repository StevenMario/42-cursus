/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_lstnew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:54:13 by mrambelo          #+#    #+#             */
/*   Updated: 2024/04/30 21:11:29 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_double_lstnew(t_stack **stack,void *data)
{
    t_stack   *new_stack;
    new_stack = malloc(sizeof(t_stack));
    if (!new_stack)
    {
        return (NULL);
    }
    new_stack->prev= NULL;
    new_stack->data = data;
    new_stack->next= NULL;
    if (*stack != NULL) {
        (*stack)->prev = new_stack;
    }
    *stack = new_stack;
    return (new_stack);
}