/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlachau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:37:38 by rlachau           #+#    #+#             */
/*   Updated: 2021/11/01 18:38:37 by rlachau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*last;
	t_list	*elem;
	void	*content;

	new_lst = NULL;
	last = NULL;
	while (lst)
	{
		content = f(lst->content);
		elem = ft_lstnew(content);
		if (!elem)
		{
			if (new_lst)
				ft_lstclear(&new_lst, del);
			return (NULL);
		}
		if (last)
			last->next = elem;
		if (!new_lst)
			new_lst = elem;
		last = elem;
		lst = lst->next;
	}
	return (new_lst);
}
