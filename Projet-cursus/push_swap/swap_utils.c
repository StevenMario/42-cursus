/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:21:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/10 13:39:16 by mrambelo         ###   ########.fr       */
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

void ft_lstclear(t_stack **lst)
{
    t_stack *temp;
    t_stack *next;

    temp = (*lst);
    if (temp == NULL)
        return ;
    else
    {
        while (temp != NULL)
        {
            next = (temp)->next;
            free(temp);
            temp = next;
        }
        *lst = NULL;
    }
}

t_stack *ft_lstlast(t_stack **lst)
{
    t_stack  *temp;

   
    if (!(*lst))
        return (NULL);
    temp = (*lst);
    while (temp)
    {
        temp = temp->next;
        if (temp->next == NULL)
            return (temp);
    }
    return (temp);
}

void free_split(char **str)
{
    int i;

    i = 0;
    while (str[i] != NULL)
    {
        free(str[i]);
        i++;
    }
    free(str);
}
