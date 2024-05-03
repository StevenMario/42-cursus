/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:21:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/03 13:40:34 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"
 
void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *temp;

    temp = *lst;
    while(temp)
    {
        temp = temp->next;
        if (temp->next == NULL)
         {
            temp->next = new;
            new->next = NULL;
            break;
         }   

    }
}