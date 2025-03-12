/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:19:05 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/14 17:28:41 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_error(char *error, int mod_exit)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("\nError: ", 2);
	ft_putendl_fd(error, 2);
	ft_putstr_fd(BLANK, 2);
	if (mod_exit)
		exit(0);
}

void	kill_check(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
		ft_error("Signal handeling", FALSE);
}
