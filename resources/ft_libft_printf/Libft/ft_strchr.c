/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:19:59 by ymohamed          #+#    #+#             */
/*   Updated: 2022/07/17 17:51:43 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	m;
	int		i;

	ptr = (char *)s;
	m = (char )c;
	i = 0;
	while (ptr[i] != m && ptr[i] != '\0')
	{
		i++;
	}
	if (ptr[i] != m)
		return (0);
	return (&ptr[i]);
}
