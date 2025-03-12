/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:12:56 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/14 19:22:42 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"
#include <signal.h>
#include <unistd.h>

void	send_bit(char *message, pid_t pid)
{
	static int				i = 8;
	static unsigned char	c;
	static char				*str;
	static pid_t			server_pid;

	if (message)
	{
		str = message;
		server_pid = pid;
		c = *str;
	}
	if (!i)
	{
		i = 8;
		c = *(++str);
		if (!c)
			exchange_completed(server_pid);
	}
	if (c && c >> --i & 0x01)
		kill_check(server_pid, SIGUSR1);
	else if (c)
		kill_check(server_pid, SIGUSR2);
}

void	handler(int sig, siginfo_t *siginfo, void *vide)
{
	static int	bytes = 0;

	(void)siginfo;
	(void)vide;
	if (sig == SIGUSR1)
		ft_printf("\rBytes sent: %i\n", ++bytes);
	send_bit(0, 0);
}

void	ft_read(int ac, char **av, pid_t pid)
{
	char	*file;
	char	str[5000];
	int		i;

	if (ac == 2)
	{
		i = 0;
		ft_bzero(str, 5000);
		i = read(STDIN_FILENO, str + i, 4999 - i);
		while (ft_strchri(str + i - 1, '\n') == -1)
			i = read(STDIN_FILENO, str + i, 4999 - i);
		send_bit(str, pid);
	}
	else if (ac == 3)
	{
		file = readfile(av[2]);
		if (file == NULL)
			send_bit(av[2], pid);
		else
		{
			send_bit(file, pid);
			free(file);
		}
	}
}

int	main(int ac, char **av)
{
	struct sigaction	client;
	pid_t				pid;

	check_arg(ac, av);
	check_pid(av[1]);
	pid = ft_atoi_base(av[1], "0123456789");
	if (pid < 1)
		ft_error("Invalid PID", TRUE);
	ft_memset(&client, 0, sizeof(client));
	sigemptyset(&client.sa_mask);
	sigaddset(&client.sa_mask, SIGUSR1);
	sigaddset(&client.sa_mask, SIGUSR2);
	client.sa_flags = SA_RESTART | SA_SIGINFO;
	client.sa_sigaction = handler;
	sigaction(SIGUSR1, &client, 0);
	sigaction(SIGUSR2, &client, 0);
	ft_read(ac, av, pid);
	while (1)
		pause();
	return (0);
}
