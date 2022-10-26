/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_printf.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:40:32 by ymohamed          #+#    #+#             */
/*   Updated: 2022/10/17 21:00:37 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_PRINTF_H
# define FT_LIBFT_PRINTF_H

# include "./Libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef unsigned long	t_ul;
int		ft_printf(const char *s, ...);
void	ft_printhexp(size_t val, char *base, int *n);
void	ft_printhex(unsigned int val, char *base, int *n);

#endif
