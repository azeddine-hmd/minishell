/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:14:21 by hboudhir          #+#    #+#             */
/*   Updated: 2021/10/29 17:13:35 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	exec_bin(char **cmd, char **env)
{
	char	**path;
	int		i;
	int		ret;	

	i = -1;
	ret = 0;
	g_sign.child_running = true;
	if (cmd[0][0] == '.' || cmd[0][0] == '/')
		return (exec_path(cmd, env));
	path = split_path(env);
	if (!path)
		return (2);
	while (path[++i])
	{
		ret = execute_p(ft_pathjoin(path[i], cmd[0]), cmd, env);
		if (!ret || ret != 127)
			break ;
	}
	ft_freestrarr(path);
	return (ret);
}

int	check_cmd(t_cmd *cmd, char ***env)
{
	int		ret;

	ret = 0;
	if (!cmd)
		return (0);
	if (cmd->args[0][0] != '\0')
	{
		ret = exec_builtin(cmd->args, env);
		if (ret != 2)
			return (ret);
		if (!find_strenv("PATH", *env))
			ret = 2;
		else
		{
			ret = exec_bin(cmd->args, *env);
			if (ret != 2 && ret != 127)
				return (ret);
		}
		if (ret == 2)
			return (file_error(cmd->args[0]));
	}
	return (cmd_nfound(cmd->args[0]));
}

int	exec_cmd(t_cmd *cmd, char ***env)
{
	int		fd_in;
	int		fd_out;
	int		ret;

	ret = 0;
	if (cmd->in_token || cmd->out_token)
	{
		fd_in = dup(0);
		fd_out = dup(1);
		if (redirections(cmd))
			return (1);
	}
	ret = check_cmd(cmd, env);
	if (cmd->in_token || cmd->out_token)
	{	
		dup2(fd_in, 0);
		dup2(fd_out, 1);
		close(fd_in);
		close(fd_out);
	}
	return (ret);
}

int	main_function(t_list *cmds, char ***env)
{
	static int	r;
	t_cmd		*cmd;
	t_list		*head;

	head = cmds;
	r = 0;
	while (cmds)
	{
		cmd = (t_cmd *)cmds->content;
		cmd->ret = r;
		if (!cmd->args)
		{
			cmds = cmds->next;
			continue ;
		}
		if (cmds->next)
			cmds = pipes(cmds, env);
		else
			r = exec_cmd(cmd, env);
		cmds = cmds->next;
	}
	cmds = head;
	return (r);
}

void	execute(t_list *cmds, char ***env)
{
	char	*ret;

	print_all_cmds(cmds);
	ret = ft_itoa(main_function(cmds, env));
	g_sign.child_running = false;
	*env = export_var("?", ret, *env);
	free(ret);
	return ;
}
