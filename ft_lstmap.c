/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:27:07 by laliao            #+#    #+#             */
/*   Updated: 2021/01/11 03:16:50 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*destlist;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	if (!(destlist = ft_lstnew(lst->content)))
		return (NULL);
	tmp = destlist;
	while (lst)
	{
		(*f)(lst->content);
		(*f)(tmp->content);
		lst = lst->next;
		if (lst)
		{
			if (!(tmp->next = ft_lstnew(lst->content)))
			{
				ft_lstclear(&destlist, del);
				return (NULL);
			}
			tmp = tmp->next;
		}
	}
	return (destlist);
}
