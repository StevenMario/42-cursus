/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_lstnew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:54:13 by mrambelo          #+#    #+#             */
/*   Updated: 2024/04/30 13:11:41 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_double_lstnew(void **data)
{
    t_stack   *new_list;
    new_list = malloc(sizeof(t_stack));
    if (!new_list)
    {
        return (NULL);
    }
    new_list->prev= NULL;
    new_list->data = data;
    new_list->next= NULL;
    return (new_list);
}