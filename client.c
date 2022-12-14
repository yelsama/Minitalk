/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:15:23 by ymohamed          #+#    #+#             */
/*   Updated: 2022/10/26 13:19:57 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_client.h"

static void	send_bit(unsigned char bit, int pid)
{
	int	back_sig;

	back_sig = 0;
	if (bit == 0)
		back_sig = kill(pid, SIGUSR1);
	else if (bit == 1)
		back_sig = kill(pid, SIGUSR2);
	if (back_sig == -1)
	{
		ft_printf("Could not get to the specified pid\nExiting\n");
		exit(0);
	}
	usleep(60);
}

static void	cipher_send_msg(char *str, int pid)
{
	unsigned char	mask;
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
	}
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
