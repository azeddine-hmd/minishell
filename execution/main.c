#include "execution.h"
# define true 1


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
	//TODO: free everything before exiting.
	// also check the correction paper +  https://www.gnu.org/software/bash/manual/html_node/Exit-Status

	(void)cmd;
	write(1, "exit\n", 5);
	if (length(cmd) == 2)
		if (!is_str_digit(cmd[1]))
			bad_exit(cmd[1]);
		else
			exit((unsigned char)ft_atoi(cmd[1]));
	else if (length(cmd) > 2)
	{
		if (!is_str_digit(cmd[1]))
			bad_exit(cmd[1]);
		else
			return(exit_many());
	}
	exit((unsigned char)ret);
	return (0);
}

int			cmd_nfound(char *str)
{
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2,": command not found\n", 20);
	return (127);
}

int			exec_builtin(char **cmd, char ***env, int ret) // ["cd", ...]
{
	if (!ft_strcmp(cmd[0], "echo")) // no memleak
		return (ft_builtin_echo(cmd));
	else if (!ft_strcmp(cmd[0], "cd")) // no memleak
		return (ft_builtin_cd(cmd + 1, env));
	else if (!ft_strcmp(cmd[0], "pwd")) // no memleak
		return (ft_builtin_pwd());
	else if (!ft_strcmp(cmd[0], "export")) // not working
		return (ft_builtin_export(cmd + 1, env));
	else if (!ft_strcmp(cmd[0], "unset")) // not working
		return (ft_builtin_unset(cmd + 1, env));
	else if (!ft_strcmp(cmd[0], "env")) // no memleak
		return (ft_builtin_env(*env));
	else if (!ft_strcmp(cmd[0], "exit")) // not working
		return (ft_builtin_exit(cmd, ret));
	return (2);
}

int			run_cmd(char *exec_path, char **args, char **env)
{
	pid_t	pid;
	int 	ret;
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


int			execute_p(char *p, char **cmd, char **env)
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

int			exec_path(char **cmd, char **env)
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

char		**split_path(char **env)
{
	char	*tmp;
	char	**path;

	tmp = ft_substr(find_strenv("PATH", env), 5, ft_strlen(find_strenv("PATH", env))); // check if num 5 is good enough
	path = ft_split(tmp, ':');
	free(tmp);
	return (path);
}

int			exec_bin(char **cmd, char **env)		// equal to check_bin();
{
	char **path;
	int	i;
	int	ret;	

	i = -1;
	ret = 0;
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

 int	file_error(char *s)
{
	write(2, "minishell: ", 11);
	write(2, s, strlen(s));
	write(2, ": No such file or directory\n", 28);
	return (127);
}

int			check_cmd(t_cmd *cmd, char ***env)
{
	int		ret;
	FILE *fd = fopen("/tmp/pipe_debugging", "a+");
	ret = 0;
	if (!cmd)
		return (0);
	if (cmd->args[0][0] != '\0')
	{
		ret = exec_builtin(cmd->args, env, cmd->ret); // changes this line [04/10/21] edit1: there's memory leak here
		if (ret != 2)
		{
			fprintf(fd, "Return value of the command: %s is: %d\n", cmd->args[0], ret);
			fflush(fd);
			return (ret);
		}
		if (!find_strenv("PATH", *env)[0])
			ret = 2;
		else
		{
			ret = exec_bin(cmd->args, *env);
			if (ret != 2 && ret != 127)
			{
				fprintf(fd, "Return value of the command: %s is: %d\n", cmd->args[0], ret);
				fflush(fd);
				return (ret);
			}
		}
		if (ret == 2)
		{
			fprintf(fd, "Return value of the command: %s is: %d\n", cmd->args[0], ret);
			fflush(fd);
			return (file_error(cmd->args[0]));
		}
	}
	//if (ret == 127)
		//return (file_dont_exist(cmd->args[0]));
	fprintf(fd, "Return value of the command: %s is: %d does not exist\n", cmd->args[0], ret);
	fflush(fd);
	//char **path = split_path(*env);
	//for (int i = 0; path[i]; i++)
	//{
	//	fprintf(fd, "Path num: %d is: %s\n",i, path[i]);
	//	fflush(fd);
	//}
	return (cmd_nfound(cmd->args[0]));
}

int			exec_cmd(t_cmd* cmd, char ***env)
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
	////ret = 
	if (cmd->in_token || cmd->out_token)
	{	
		dup2(fd_in, 0);
		dup2(fd_out, 1);
		close(fd_in);
		close(fd_out);
	}
	return (ret);
}

int			main_function(t_list *cmds, char ***env)
{
	static int		r;
	t_cmd	*cmd;
	t_list	*head;

	head = cmds;
	r = 0;
	while (cmds)
	{
		cmd = (t_cmd*)cmds->content;
		cmd->ret = r;
		if (!length(cmd->args))
		{
			cmds = cmds->next;
			continue ;
		}
		if (cmds->next)
			cmds = pipes(cmds, env); // done [must add a head t_list to preserve the head or else pipe breaks]
		else
			r = exec_cmd(cmd, env);
		cmds = cmds->next;
	}
	cmds = head;
	return (r);
}