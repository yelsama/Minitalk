/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 01:27:48 by ymohamed          #+#    #+#             */
/*   Updated: 2022/07/29 06:13:47 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final;
	t_list	*toadd;

	final = 0;
	while (lst)
	{
		toadd = ft_lstnew(f(lst->content));
		if (toadd == 0)
		{
			ft_lstclear(&final, del);
			return (0);
		}
		ft_lstadd_back(&final, toadd);
		lst = lst->next;
	}
	return (final);
}
