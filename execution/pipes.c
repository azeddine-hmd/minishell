/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boodeer <boodeer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:16:10 by hboudhir          #+#    #+#             */
/*   Updated: 2021/10/07 19:42:52 by boodeer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int			close_all(int input, int fd1, int fd2, int pos)
{
	if (input)
		close (input);
	close(fd2);
	if (pos == 2)
		close(fd1);
	input = fd1;
	return (input);
}

// Equal to next->id (minishell_240)

int		dup_fd(t_cmd *cmd, int fds[2], int input, int fd_zero)
{
	input++;
	if (cmd->is_piped == 0 && cmd->next->is_piped == 1) // id = 1
		dup2(fds[1], 1);
	else if (cmd->is_piped && cmd->next && cmd->next->is_piped) // id = 2
	{
		dup2(fd_zero, 0);
		dup2(fds[1], 1);
	}
	else													// id = 
		dup2(fd_zero, 0);
	if (cmd->is_piped && cmd->next && cmd->next->is_piped)
		return(2);
	return (0);
}

t_cmd			*pipes(t_cmd *cmd)
{
	t_cmd 	*head;
	int		fds[2];
	int		pid;
	int		input  = 0;
	int		pos = 0;
	int		fd_zero = 0;
	head = cmd;
	while (cmd)
	{
		//if (cmd->next) // (?)
		pipe(fds);
		pid = fork();
		if (!pid)
		{
			pos = dup_fd(cmd, fds, input, fd_zero);
			close(fds[1]);
			close(fds[0]);
			close(fd_zero);
			exit(exec_bin(cmd->args));
		}
		if (fd_zero)
			close(fd_zero);
		fd_zero = fds[0];
		//input = close_all(input, fds[0], fds[1], pos); must check before delete
		if (!cmd->next || !cmd->next->is_piped)
			break ;
		cmd = cmd->next;
		close(fds[1]);
	}
	while (wait(&pid) != -1)
		;
	if (WIFEXITED(pid))
		cmd->err = WEXITSTATUS(pid);
	return (cmd);
}