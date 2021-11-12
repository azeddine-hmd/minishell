/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:48:34 by hboudhir          #+#    #+#             */
/*   Updated: 2021/11/08 21:17:38 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	cmd_nfound(char *str)
{
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": command not found\n", 20);
	return (127);
}

int	exec_builtin(char **cmd, char ***env)
{
	char	*tmp;

	tmp = xsubstr(find_strenv("?", *env), 2,
			ft_strlen(find_strenv("?", *env)));
	if (!ft_strcmp(cmd[0], "echo"))
		return (ft_builtin_echo(cmd));
	else if (!ft_strcmp(cmd[0], "cd"))
		return (ft_builtin_cd(cmd + 1, env));
	else if (!ft_strcmp(cmd[0], "pwd"))
		return (ft_builtin_pwd(*env));
	else if (!ft_strcmp(cmd[0], "export"))
		return (ft_builtin_export(cmd + 1, env));
	else if (!ft_strcmp(cmd[0], "unset"))
		return (ft_builtin_unset(cmd + 1, env));
	else if (!ft_strcmp(cmd[0], "env"))
		return (ft_builtin_env(*env));
	else if (!ft_strcmp(cmd[0], "exit"))
		return (ft_builtin_exit(cmd, ft_atoi(tmp)));
	xfree(tmp);
	return (2);
}

int	run_cmd(char *exec_path, char **args, char **env)
{
	pid_t	pid;
	int		ret;

	if (g_sign.is_pipe == true)
		execve(exec_path, args, env);
	pid = fork();
	if (pid == 0)
	{
		if (execve(exec_path, args, env) < 0)
			check_dir(args[0]);
	}
	else if (pid < 0)
	{
		write(2, "Failed to create fork\n", ft_strlen("Failed to create fork\n"));
		return (1);
	}
	waitpid(pid, &ret, 0);
	return (sig_return(ret));
}

int	execute_p(char *p, char **cmd, char **env)
{
	int		ret;

	ret = 0;
	if (open(p, O_RDONLY) <= 0)
	{
		open_failed(cmd[0]);
		xfree(p);
		return (127);
	}
	else
	{
		ret = run_cmd(p, cmd, env);
		if (ret)
		{
			xfree(p);
			return (ret);
		}
	}
	xfree(p);
	return (ret);
}

int	exec_path(char **cmd, char **env)
{
	char	*tmp;
	int		ret;
	char	*tmp1;

	if (cmd[0][0] == '.')
	{
		tmp1 = getcwd(NULL, 0);
		tmp = xstrjoin(tmp1, "/");
		free(tmp1);
		ret = execute_p(xstrjoin(tmp, cmd[0]), cmd, env);
		xfree(tmp);
		if (ret == 127)
			ret = 2;
		return (ret);
	}
	if (cmd[0][0] == '/')
	{
		ret = execute_p(xstrdup(cmd[0]), cmd, env);
		if (ret == 127)
			ret = 2;
		return (ret);
	}
	return (0);
}
