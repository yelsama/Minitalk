/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:52:29 by ymohamed          #+#    #+#             */
/*   Updated: 2022/07/25 14:03:52 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	i;
	unsigned int	l;

	if (!s)
		return (0);
	l = ft_strlen(s);
	i = 0;
	p = malloc(sizeof(char) * (l + 1));
	if (p == 0)
		return (0);
	while (i < l)
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
// #include <stdio.h>
// char	addtochar(unsigned int i, char c)
// {
// 	char	new;

// 	(void)i;
// 	new = c + 1;

// 	return (new);
// }

// int	main(void)
// {
// 	char	s[] = "ACEGIL";
// 	char	*news;
// 	news = ft_strmapi(s, *addtochar);
// 	puts(news);
// 	return (0);
// }