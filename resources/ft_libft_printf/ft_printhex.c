/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:58:05 by ymohamed          #+#    #+#             */
/*   Updated: 2022/10/10 08:07:19 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft_printf.h"

void	ft_printhexp(size_t val, char *base, int *n)
{
	if (val > 15)
	{
		*n = *n + 1;
		ft_printhexp(val / 16, base, n);
	}	
	write(1, &base[val % 16], 1);
}

void	ft_printhex(unsigned int val, char *base, int *n)
{
	if (val > 15)
	{
		*n = *n + 1;
		ft_printhex(val / 16, base, n);
	}	
	write(1, &base[val % 16], 1);
}
