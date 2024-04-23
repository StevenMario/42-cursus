/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:20:58 by mariosteven       #+#    #+#             */
/*   Updated: 2024/04/23 20:44:19 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    t_list  *temp;
    int i;
    i = 0;
   

    temp = lst;
    while (temp)
    {
        temp = temp->next;
        i++;
    }
    return (i);
}