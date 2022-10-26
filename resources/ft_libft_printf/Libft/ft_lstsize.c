/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 01:28:09 by ymohamed          #+#    #+#             */
/*   Updated: 2022/07/29 01:46:17 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		i;

	if (lst == 0)
		return (0);
	tmp = lst;
	i = 1;
	while (tmp->next != 0)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
