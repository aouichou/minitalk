/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:50:41 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/14 19:23:03 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"
#include <signal.h>

void	handler(int sig, siginfo_t *siginfo, void *vide)
{
	static unsigned char	c = 0x00;
	static int				count = 0;
	static pid_t			client_pid = 0;

	(void)vide;
	if (!client_pid)
		client_pid = siginfo->si_pid;
	c |= (sig == SIGUSR1);
	if (++count == 8)
	{
		count = 0;
		if (c == 0x00)
		{
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0x00;
		kill_check(client_pid, SIGUSR1);
	}
	else
	{
		c <<= 1;
		kill_check(client_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	server;

	ft_printf("%sPID == [%i]%s\n", YELLOW, getpid(), BLANK);
	ft_memset(&server, 0, sizeof(server));
	sigemptyset(&server.sa_mask);
	sigaddset(&server.sa_mask, SIGUSR1);
	sigaddset(&server.sa_mask, SIGUSR2);
	server.sa_flags = SA_RESTART | SA_SIGINFO;
	server.sa_sigaction = handler;
	sigaction(SIGUSR1, &server, 0);
	sigaction(SIGUSR2, &server, 0);
	while (1)
		pause();
	return (0);
}
