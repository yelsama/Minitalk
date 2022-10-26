/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:15:23 by ymohamed          #+#    #+#             */
/*   Updated: 2022/10/26 12:31:30 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_client_bonus.h"

static void	message_decipher(int sig)
{
	(void) sig;
}

static int	aknowledge_receive(int *total_sent)
{
	struct sigaction	sa;

	sa.sa_handler = &message_decipher;
	sigaction(SIGUSR1, &sa, NULL);
	pause();
	(*total_sent)++;
	return (0);
}

static void	send_bit(unsigned char bit, int pid)
{
	int	back_sig;

	back_sig = 0;
	usleep(40);
	if (bit == 0)
		back_sig = kill(pid, SIGUSR1);
	else if (bit == 1)
		back_sig = kill(pid, SIGUSR2);
	if (back_sig == -1)
	{
		ft_printf("Could not get to the specified pid\nExiting\n");
		exit(0);
	}
}

static void	cipher_send_msg(char *str, int pid)
{
	unsigned char	mask;
	static int		total_sent;
	int				byte_cnt;
	int				i;

	mask = 1;
	i = -1;
	while (str[++i])
	{
		byte_cnt = 0;
		send_bit(str[i] & mask, pid);
		while (++byte_cnt < 8)
			send_bit((str[i] >> byte_cnt) & mask, pid);
		aknowledge_receive(&total_sent);
		usleep(40);
	}
	ft_printf("total byte send is %d\n", total_sent);
	usleep(40);
}

int	main(int argc, char **argv)
{
	int				pid;
	char			*pid_check;
	char			*temp;

	if (argc != 3 || argv[1][0] < '0' || argv[1][0] > '9')
	{
		ft_printf("Client has incorrect arguments");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	pid_check = argv[1];
	while (*pid_check == '0')
		pid_check++;
	temp = ft_itoa(pid);
	if (pid < 0 || ft_strlen(temp) != ft_strlen(pid_check))
	{
		free(temp);
		ft_printf("the pid you entered is invalid");
		return (0);
	}
	free(temp);
	usleep(40);
	cipher_send_msg(argv[2], pid);
	return (0);
}
