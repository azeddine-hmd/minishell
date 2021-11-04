/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:16:10 by hboudhir          #+#    #+#             */
/*   Updated: 2021/11/03 18:02:26 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	close_all(int input, int fd1, int fd2, t_list *cmd)
{
	if (input)
		close (input);
	close(fd2);
	if (!cmd->next)
		close(fd1);
	input = fd1;
	return (input);
}

int	dup_fd(t_list *cmds, int fds[2], int input)
{
	t_cmd	*cmd;
	t_cmd	*next;

	cmd = (t_cmd *)cmds->content;
	if (cmds->next)
		next = (t_cmd *)cmds->next->content;
	if (cmd->is_piped == 0 && next->is_piped == 1)
		dup2(fds[1], 1);
	else if (cmd->is_piped && cmds->next && next->is_piped)
	{
		dup2(input, 0);
		dup2(fds[1], 1);
	}
	else
		dup2(input, 0);
	return (0);
}

void	pipe_helper(t_list *cmds, int fds[2], int input, char ***env)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)cmds->content;
	dup_fd(cmds, fds, input);
	close(fds[1]);
	close(fds[0]);
	close(input);
	g_sign.is_pipe = true;
	shell_exit(exec_cmd(cmd, env));
}

t_list	*pipes(t_list *cmds, char ***env)
{
	t_cmd	*cmd;
	int		fds[2];
	int		pid;
	int		input;

	while (cmds)
	{
		cmd = (t_cmd *)cmds->content;
		pipe(fds);
		pid = fork();
		if (!pid)
			pipe_helper(cmds, fds, input, env);
		input = close_all(input, fds[0], fds[1], cmds);
		if (!cmds->next || !((t_cmd *)cmds->next->content)->is_piped)
			break ;
		cmds = cmds->next;
		close(fds[1]);
	}
	while (wait(&pid) != -1)
		;
	if (WIFEXITED(pid))
		cmd->ret = WEXITSTATUS(pid);
	g_sign.is_pipe = false;
	return (cmds);
}
