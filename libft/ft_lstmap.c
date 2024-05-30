/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:20:17 by leochen           #+#    #+#             */
/*   Updated: 2023/11/22 14:14:15 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*new_next;

	if (!f || !del)
		return (NULL);
	lst2 = NULL;
	while (lst != NULL)
	{
		new_next = ft_lstnew((*f)(lst->content));
		if (!(new_next))
		{
			while (lst2)
			{
				new_next = lst2->next;
				(*del)(lst2->content);
				free(lst2);
				lst2 = new_next;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&lst2, new_next);
		lst = lst->next;
	}
	return (lst2);
}
