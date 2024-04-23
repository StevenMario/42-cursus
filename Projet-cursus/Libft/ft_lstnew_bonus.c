/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:43:39 by mariosteven       #+#    #+#             */
/*   Updated: 2024/04/23 11:35:43 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
t_list *ft_lstnew(void *content)
{
    t_list  *new_list;
    new_list = malloc(sizeof(t_list));
    if (!new_list)
    {
        return (NULL);
    }
    new_list->content = content;
    new_list->next= NULL;
    return (new_list);
}