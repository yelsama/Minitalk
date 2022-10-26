/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:09:03 by ymohamed          #+#    #+#             */
/*   Updated: 2022/07/19 11:41:04 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *d, const char *s, size_t k)
{
	size_t	i;
	size_t	m;

	i = 0;
	m = 0;
	while (s[i] != '\0')
		i++;
	if (k == 0)
		return (i);
	while (m < (k -1) && s[m] != '\0')
	{
		d[m] = s[m];
		m++;
	}
	d[m] = '\0';
	return (i);
}
