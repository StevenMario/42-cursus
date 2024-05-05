/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:21:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/05 22:04:46 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"
 
void ft_lstadd_back(t_stack **lst, t_stack *new)
{
    t_stack  *temp;

    temp = *lst;
    while(temp)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            
            temp->next = new;
            new->prev = temp;
            new->next = NULL;
            break;
        }
    }
}
t_stack *ft_double_lstnew(int nbr)
{
	t_stack   *new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack || !nbr)
		return (NULL);
	new_stack->prev= NULL;
	new_stack->nbr = nbr;
	new_stack->next= NULL;
	return (new_stack);
}