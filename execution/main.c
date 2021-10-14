#include "execution.h"
# define true 1


int	ft_builtin_exit(int ret)
{
	//TODO: free everything before exiting.
	// also check the correction paper +  https://www.gnu.org/software/bash/manual/html_node/Exit-Status
	exit(ret);
	return (0);
}

int			cmd_nfound(char *str)
{
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2,": command not found\n", 19);
	return (127);
}

int			exec_builtin(char **cmd, char **env) // ["cd", ...]
{
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
		return (ft_builtin_env(env));
	else if (!ft_strcmp(cmd[0], "exit"))
		return (ft_builtin_exit(10));
	return (2);
}

int			run_cmd(char *exec_path, char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(exec_path, args, g_env);
	else if (pid < 0)
	{
		free(exec_path);
		write(1, "Failed to create fork\n", ft_strlen("Failed to create fork\n"));
		return (-1);
	}
	wait(&pid);
	if (exec_path)
		free(exec_path);
	return (1);
}

int			is_exec(char *exec_path, struct stat stats, char **cmd) // check better this function
{
	if (stats.st_mode & S_IFREG)
	{
		if (stats.st_mode & S_IXUSR)
			return (run_cmd(exec_path, cmd));
		else
			error_msg("Permission denied!\n", 2, 0);
		free(exec_path);
		return (1);
	}
	free(exec_path);
	return (0);
}

int			exec_bin(char **cmd, char **env)		// equal to check_bin();
{
	printf("%s\n", env[1]);
	char	**path = ft_split(getenv("PATH"), ':');
	int		i;
	char	*exec_path;
	struct stat stats;

	i = -1;
	while (path && path[++i])
	{
		if (ft_strstartw(cmd[0], path[i]))
			exec_path = ft_strdup(cmd[0]);
		else
			exec_path = ft_pathjoin(path[i], cmd[0]);
		if (lstat(exec_path, &stats) == -1)
			free(exec_path);
		else
		{
			ft_freestrarr(path);
			return (is_exec(exec_path, stats, cmd));
		}
	}
	ft_freestrarr(path);
	return (0);
}

 int	file_error(char *s)
{
	write(2, "minishell: ", 11);
	write(2, s, strlen(s));
	write(2, ": No such file or directory\n", 28);
	return (127);
}

int			check_cmd(t_cmd *cmd, char **env)
{
	int		ret;

	ret = 0;
	if (!cmd) // see the difference between this and the condition below
		return (0);
	if (cmd->args[0][0] != '\0')
	{
		ret = exec_builtin(cmd->args, env); // changes this line [04/10/21]
		if (ret != 2)
			return (ret);
		if (find_strenv("PATH", env)[0] == '\0')
			ret = 2;
		else
		{
			ret = exec_bin(cmd->args, env);
			if (ret != 2 && ret != 127)
				return (ret);
		}
		if (ret == 2)
			return (file_error(cmd->args[0]));
	}
	//if (ret == 127)
		//return (file_dont_exist(cmd->args[0]));
	return (cmd_nfound(cmd->args[0]));
}

int			exec_cmd(t_cmd* cmd, char **env)
{
	//int		fd_in;
	//int		fd_out;
	int		ret;

	ret = 0;
	//if (cmd->in_token || cmd->out_token) // ToDo: fix redirection
	//{
	//	fd_in = dup(0);
	//	fd_out = dup(1);
	//	if (redirections(cmd))
	//		return (1);
	//}

	//if (cmd->in_token->content || cmd->out_token->content)
	ret = check_cmd(cmd, env);
	////ret = 
	//if (cmd->in_token || cmd->out_token)
	//{	
	//	dup2(fd_in, 0);
	//	dup2(fd_out, 1);
	//	close(fd_in);
	//	close(fd_out);
	//}
	return (ret);
}

int			main_function(t_list *cmds, char **env)
{
	int		r;

	r = 0;
	// TODO:
	// check filter_all in the other folder;
	while (cmds)
	{
		if (cmds->next)
			cmds = pipes(cmds, env);
		else
			r = exec_cmd(((t_cmd*)cmds->content), env);
		cmds = cmds->next;
	}
	return (r);
}

//int			main(int argc, char **argv, char **env)
//{
//	//printf("\n\n");
//	//t_cmd	*test = NULL;					// testing linked ist
//	t_token *token = NULL; 
//	//char	*red[] =  {"test.c", "test.txt", "test", NULL};
//	//fill_token(&token, red, "aca");
//	//output_token(token);
	//init_env(argc, argv, env);
//	char	*cmd[] = {"echo","hello", NULL};
//	//char	*cmd1[] = {"wc",NULL};
//	//exec_builtin(cmd1);
//	//redirections(token); // in the exec_func dup fd_in and fd_out before opening redirections
//	exec_bin(cmd);	
//	//printf("%s\n", getenv("PWD"));
//	//char	*cmd2[] = {"cd",NULL};
//	//exec_builtin(cmd2);
//	//test = fill_dummy(&test, cmd, cmd1);
//	//pipes(test);
//	return (0);
//}