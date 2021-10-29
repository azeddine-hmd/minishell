/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:48:34 by hboudhir          #+#    #+#             */
/*   Updated: 2021/10/29 16:39:39 by hboudhir         ###   ########.fr       */
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

	tmp = ft_substr(find_strenv("?", *env), 2,
			ft_strlen(find_strenv("?", *env)));
	if (!ft_strcmp(cmd[0], "echo"))
		return (ft_builtin_echo(cmd));
	else if (!ft_strcmp(cmd[0], "cd"))
		return (ft_builtin_cd(cmd + 1, env));
	else if (!ft_strcmp(cmd[0], "pwd"))
		return (ft_builtin_pwd());
	else if (!ft_strcmp(cmd[0], "export"))
		return (ft_builtin_export(cmd + 1, env));
	else if (!ft_strcmp(cmd[0], "unset"))
		return (ft_builtin_unset(cmd + 1, env));
	else if (!ft_strcmp(cmd[0], "env"))
		return (ft_builtin_env(*env));
	else if (!ft_strcmp(cmd[0], "exit"))
		return (ft_builtin_exit(cmd, ft_atoi(tmp)));
	free(tmp);
	return (2);
}

int	run_cmd(char *exec_path, char **args, char **env)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == 0)
		execve(exec_path, args, env);
	else if (pid < 0)
	{
		write(2, "Failed to create fork\n", ft_strlen("Failed to create fork\n"));
		return (1);
	}
	waitpid(pid, &ret, 0);
	ret = WEXITSTATUS(ret);
	return (ret);
}

int	execute_p(char *p, char **cmd, char **env)
{
	int		ret;

	ret = 0;
	if (open(p, O_RDONLY) <= 0)
	{
		free(p);
		return (127);
	}
	else
	{
		ret = run_cmd(p, cmd, env);
		if (ret)
		{
			free(p);
			return (ret);
		}
	}
	free(p);
	return (ret);
}

int	exec_path(char **cmd, char **env)
{
	char	*tmp;
	int		ret;

	if (cmd[0][0] == '.')
	{
		tmp = ft_strjoin(getcwd(NULL, 0), "/");
		ret = execute_p(ft_strjoin(tmp, cmd[0]), cmd, env);
		free(tmp);
		if (ret == 127)
			ret = 2;
		return (ret);
	}
	if (cmd[0][0] == '/')
	{
		ret = execute_p(ft_strdup(cmd[0]), cmd, env);
		if (ret == 127)
			ret = 2;
		return (ret);
	}
	return (0);
}
