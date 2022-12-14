/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:15:54 by ymohamed          #+#    #+#             */
/*   Updated: 2022/10/26 13:14:12 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_client.h"

static void	message_decipher(int sig)
{
	static unsigned char	byte;
	static int				shift;
	unsigned char			mask;

	mask = 1;
	if (sig == SIGUSR1)
		shift++;
	else if (sig == SIGUSR2)
	{
		byte = byte | (mask << shift);
		shift++;
	}
	else
		ft_printf("###got uknown signal###\n");
	if (shift == 8)
	{
		write(1, &byte, 1);
		byte = '\0';
		shift = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID is: %d\n", getpid());
	signal(SIGUSR1, &message_decipher);
	signal(SIGUSR2, &message_decipher);
	while (1)
		pause();
	return (0);
}
