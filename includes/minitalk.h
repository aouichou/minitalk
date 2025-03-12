/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:16:29 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/13 03:37:44 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../includes/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>

# define RED	       		"\033[1;31m"
# define GREEN	       		"\033[1;32m"
# define CYAN	       		"\033[1;36m"
# define BLUE	       		"\033[1;34m"
# define YELLOW	       		"\033[1;33m"
# define BLANK	       		"\033[0m"

# define USAGE	"Usage : ./client [PID] [message or file] or \
./client [PID] to read from STDIN"

enum	e_bool
{
	FALSE,
	TRUE
};

void		send_bit(char *message, pid_t pid);
void		ft_read(int ac, char **av, pid_t pid);

void		check_arg(int ac, char **av);
int			check_pid(char *pid);
char		*readfile(char *file_name);
void		exchange_completed(pid_t server_pid);

void		ft_error(char *error, int mod_exit);
void		kill_check(pid_t pid, int sig);

#endif
