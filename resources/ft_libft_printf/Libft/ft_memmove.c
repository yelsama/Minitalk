/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:52:03 by ymohamed          #+#    #+#             */
/*   Updated: 2022/07/19 21:16:14 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	const char		*sptr;
	char			*dptr;
	size_t			i;

	if (!(d || s))
		return (0);
	sptr = s;
	dptr = d;
	i = 0;
	while (i < n && dptr <= sptr)
	{
		dptr[i] = sptr[i];
		i++;
	}
	while (dptr > sptr && n > 0)
	{
		dptr[n - 1] = sptr[n - 1];
		n--;
	}
	return (d);
}
