/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:21:42 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/13 03:19:19 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	exchange_completed(pid_t server_pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		usleep(50);
		kill_check(server_pid, SIGUSR2);
	}
	ft_printf("%s%s%s\n", GREEN, "Exchange succeeded", BLANK);
	exit(0);
}

char	*readfile(char *file_name)
{
	FILE	*file;
	long	size;
	char	*str;

	file = fopen(file_name, "rb");
	if (file == NULL)
		return (NULL);
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);
	str = malloc(size + 1);
	if (!str)
		ft_error("Malloc error", TRUE);
	fread(str, size, 1, file);
	fclose(file);
	str[size] = '\0';
	return (str);
}

void	check_arg(int ac, char **av)
{
	if (ac == 1 || ac > 3)
		ft_error(USAGE, TRUE);
	if (!av[1])
		ft_error(USAGE, TRUE);
}

int	check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			ft_error("Invalid PID", TRUE);
		i++;
	}
	return (0);
}
