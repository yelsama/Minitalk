/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:34:50 by ymohamed          #+#    #+#             */
/*   Updated: 2022/07/17 17:56:34 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	m;
	int		i;

	ptr = (char *)s;
	m = (char )c;
	i = 0;
	while (ptr[i] != '\0')
	{
		i++;
	}
	while (ptr[i] != m && i != 0)
	{
		i--;
	}
	if (ptr[i] != m)
		return (0);
	return (&ptr[i]);
}
