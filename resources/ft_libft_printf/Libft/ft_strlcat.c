/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 03:20:50 by ymohamed          #+#    #+#             */
/*   Updated: 2022/07/30 00:56:04 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	m;
	size_t	k;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	m = ft_strlen(dst);
	k = m + ft_strlen(src);
	i = 0;
	while (m < (dstsize -1) && src[i] != '\0')
	{
		dst[m] = src[i];
		m++;
		i++;
	}
	dst[m] = '\0';
	if (dstsize <= m)
		return (k - m + dstsize);
	return (k);
}
