/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:21:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/06 20:47:53 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"
 
void ft_lstadd_back(t_stack **lst, t_stack *new)
{
    t_stack  *temp;

    temp = *lst;
    while(temp)
    {
        if (temp->next == NULL)
        {
            
            temp->next = new;
            new->prev = temp;
            new->next = NULL;
            break;
        }
        temp = temp->next;
    }
}
t_stack *ft_double_lstnew(int nbr)
{
	t_stack   *new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->prev= NULL;
	new_stack->nbr = nbr;
	new_stack->next= NULL;
	return (new_stack);
}

void ft_lstdelone(t_stack *lst, void (*del)(void *))
{
    del((void *)&lst->nbr);
   // free(lst);
}

void ft_lstclear(t_stack **lst, void (*del)(void *))
{
    if (!lst || !(*lst))
        return ;
    if ((*lst)->next)
        ft_lstclear(&(*lst)->next, del);
    ft_lstdelone(*lst, del);
    *lst = NULL;
}

t_stack *ft_lstlast(t_stack *lst)
{
    t_stack  *temp;

   
    if (!lst)
        return (NULL);
    temp = lst;
    while (temp)
    {
        temp = temp->next;
        if (temp->next == NULL)
            return (temp);
    }
    return (temp);
}