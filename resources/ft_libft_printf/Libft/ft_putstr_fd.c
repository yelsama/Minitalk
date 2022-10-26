/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:51:40 by ymohamed          #+#    #+#             */
/*   Updated: 2022/07/30 04:26:54 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	l;
	unsigned int	i;

	if (!s || !fd)
		return ;
	l = ft_strlen(s);
	i = 0;
	while (i < l)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
