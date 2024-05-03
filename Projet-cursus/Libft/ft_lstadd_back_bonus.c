/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:32:10 by mrambelo          #+#    #+#             */
/*   Updated: 2024/04/24 13:54:00 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
