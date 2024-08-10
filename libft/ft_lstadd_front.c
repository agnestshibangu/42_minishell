/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:24:11 by agtshiba          #+#    #+#             */
/*   Updated: 2023/10/20 14:47:14 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
// void printList(t_list *list)
// {
//     while (list != NULL) 
//     {
//         printf("Element content: %s\n", (char *)list->content);
//         printf("next ptr: %s\n", (char *)list->next);
//         list = list->next;
//     }
// }
// t_list *ft_lstlast(t_list *lst)
// {
//     while (lst)
//     {
//         if (!lst->next)
//             return lst; 
//         lst = lst->next;
//     }
//     return (lst);
// }
// int main()
// {
//     t_list *mylist = NULL;
//     char *data1 = "Node 1";
//     t_list *node1 = ft_lstnew(data1);
//     if (node1)
//     {
//         ft_lstadd_front(&mylist, node1);
//     }
//     char *data2 = "Node 2";
//     t_list *node2 = ft_lstnew(data2);
//     if (node2)
//     {
//         ft_lstadd_front(&mylist, node2);
//     }
//     // t_list *lastNode = ft_lstlast(mylist); 
//     // Obtenez le dernier élément de la liste
//     // if (lastNode) {
//     //     printf("Dernier élément: %s\n", (char *)lastNode->content);
//     // } else {
//     //     printf("La liste est vide.\n");
//     // }
//     return 0;
// }t_list *ft_lstlast(t_list *lst)
// {
//     while (lst)
//     {
//         if (!lst->next)
//             return lst; 
//         lst = lst->next;
//     }
//     return (lst);
// }
