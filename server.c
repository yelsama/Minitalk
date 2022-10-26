/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:15:54 by ymohamed          #+#    #+#             */
/*   Updated: 2022/10/24 21:55:43 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_client.h"

static int	aknowledge_received(int pid)
{
	usleep(80);
	kill(pid, SIGUSR1);
	return (0);
}

static void	message_decipher(int sig, siginfo_t *info, void *context)
{
	static unsigned char	byte;
	static int				shift;
	unsigned char			mask;

	(void)context;
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
		aknowledge_received(info->si_pid);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = message_decipher;
	ft_printf("Server PID is: %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
