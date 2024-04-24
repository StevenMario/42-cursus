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
#include "stdio.h"
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
/*int main()
{
    t_list *list1 = ft_lstnew((void *)4);
    t_list *list2 = ft_lstnew((void *)5);
    t_list *list3 = ft_lstnew((void *)9);
    int i;

    list1->next = list2;
    i = ft_lstsize(list1);
    printf("%d\n",i);
    ft_lstadd_back(&list1, list3);
    
    i = ft_lstsize(list1);
    printf("%d",i);
    free(list1);
    free(list2);
    free(list3);
    return 0;
}*/