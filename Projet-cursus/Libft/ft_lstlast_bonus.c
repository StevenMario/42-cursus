/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:51:46 by mariosteven       #+#    #+#             */
/*   Updated: 2024/04/23 21:23:08 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    t_list  *temp;

   
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