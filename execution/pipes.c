/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boodeer <boodeer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:16:10 by hboudhir          #+#    #+#             */
/*   Updated: 2021/10/16 21:40:39 by boodeer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
int			close_all(int input, int fd1, int fd2, t_list *cmd)
{
	if (input)
		close (input);
	close(fd2);
	if (!cmd->next)
		close(fd1);
	input = fd1;
	return (input);
}

// Equal to next->id (minishell_240)

int		dup_fd(t_list *cmds, int fds[2], int input, int fd_zero)
{
	t_cmd	*cmd;
	t_cmd	*next;

	fd_zero++;
	cmd = (t_cmd*)cmds->content;
	if (cmds->next)
		next = (t_cmd*)cmds->next->content;
	//input++; why did I add this...
	if (cmd->is_piped == 0 && next->is_piped == 1) // id = 1
		dup2(fds[1], 1);
	else if (cmd->is_piped && cmds->next && next->is_piped) // id = 0
	{
		dup2(input, 0);
		dup2(fds[1], 1);
	}
	else													// id = 2
		dup2(input, 0);
	//if (cmd->is_piped && cmds->next && next->is_piped)
		//return(2);
	return (0);
}

t_list			*pipes(t_list *cmds, char **env)
{
	t_cmd	*cmd;
	int		fds[2];
	int		pid;
	int		input; // =0; (how it used to be)
	//int		pos = 0;
	int		fd_zero = 0;
	
	while (cmds)
	{
		cmd = (t_cmd*)cmds->content;
		pipe(fds);
		pid = fork();
		if (!pid)
		{
			dup_fd(cmds, fds, input, fd_zero); // return pos = dup_fd after the check
			//close(fds[1]);
			//close(fds[0]);
			//close(fd_zero);
			exit(exec_cmd(cmd, env)); // remember to change this with exec_cmd (builtin + bin)
		}
		//if (fd_zero)
		//	close(fd_zero);
		//fd_zero = fds[0];
		input = close_all(input, fds[0], fds[1], cmds); // must check before delete
		if (!cmds->next || !((t_cmd*)cmds->next->content)->is_piped)
			break ;
		cmds = cmds->next;
		//close(fds[1]);
	}
	while (wait(&pid) != -1)
		;
	if (WIFEXITED(pid))
		cmd->ret = WEXITSTATUS(pid);
	return (cmds);
}