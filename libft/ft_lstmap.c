/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:15:15 by agtshiba          #+#    #+#             */
/*   Updated: 2023/10/23 18:20:05 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*work;

	if (!f || !lst || !del)
		return (NULL);
	begin = ft_lstnew(f(lst->content));
	work = begin;
	while (lst && lst->next)
	{
		if (!work)
			return (NULL);
		work->next = ft_lstnew(f(lst->next->content));
		work = work->next;
		lst = lst->next;
	}
	return (begin);
}
