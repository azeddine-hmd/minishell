/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:47:15 by hboudhir          #+#    #+#             */
/*   Updated: 2021/10/24 18:10:37 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	bad_exit(char *str)
{
	write(2, "minishell: exit: ", 17);
	write(2, str, ft_strlen(str));
	write(2, ": numeric argument required\n", 28);
	exit(255);
}

int	exit_many(void)
{
	write(2, "minishell: exit: too many arguments\n", 36);
	return (1);
}

int	ft_builtin_exit(char **cmd, int ret)
{
	write(1, "exit\n", 5);
	if (length(cmd) == 2)
	{
		if (!is_str_digit(cmd[1]))
			bad_exit(cmd[1]);
		else
			exit((unsigned char)ft_atoi(cmd[1]));
	}
	else if (length(cmd) > 2)
	{
		if (!is_str_digit(cmd[1]))
			bad_exit(cmd[1]);
		else
			return (exit_many());
	}
	deallocate();
	exit((unsigned char)ret);
	return (0);
}
