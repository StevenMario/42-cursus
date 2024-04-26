/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:22:09 by mrambelo          #+#    #+#             */
/*   Updated: 2024/04/26 13:56:53 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    if (!lst || !(*lst))
        return ;
    if ((*lst)->next)
        ft_lstclear(&(*lst)->next, del);
    ft_lstdelone(*lst, del);
    *lst = NULL;
}