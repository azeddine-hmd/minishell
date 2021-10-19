#include "minishell.h"
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

int			exec_builtin(char **cmd) // ["cd", ...]
{
	if (!ft_strcmp(cmd[0], "echo"))
		return (ft_builtin_echo(cmd + 1));
	else if (!ft_strcmp(cmd[0], "cd"))
		return (ft_builtin_cd(cmd + 1));
	else if (!ft_strcmp(cmd[0], "pwd"))
		return (ft_builtin_pwd());
	else if (!ft_strcmp(cmd[0], "export"))
		return (ft_builtin_export(cmd + 1));
	else if (!ft_strcmp(cmd[0], "unset"))
		return (ft_builtin_unset(cmd + 1));
	else if (!ft_strcmp(cmd[0], "env"))
		return (ft_builtin_env());
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

int			exec_bin(char **cmd)		// equal to check_bin();
{
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





void		append_lst(t_cmd **cmd, t_cmd *src)
{
	t_cmd	*tmp;

	if (*cmd == NULL)
		*cmd = src;
	else
	{
		tmp = *cmd;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = src;
	}
}

t_cmd		*fill_dummy(t_cmd **cmd, char **cmd_0, char **cmd_1)
{
	int		i;
	t_cmd	*dummy;
	i = 0;
	while (i < 2)
	{
		dummy = (t_cmd *)malloc(sizeof(t_cmd));
		dummy->pos = i;
		switch (i)
		{
		case 0:
			dummy->is_piped = 0;
			dummy->previous = NULL;
			dummy->next = NULL;
			dummy->args = cmd_0;
			break;
		case 1:
			dummy->is_piped = 1;
			dummy->next = NULL;
			dummy->args = cmd_1;
		default:
			break;
		}
		append_lst(cmd ,dummy);
		i++;
	}
	return (*cmd);
}

void		append_lstk(t_token **cmd, t_token *src)
{
	t_token	*tmp;

	if (*cmd == NULL)
		*cmd = src;
	else
	{
		tmp = *cmd;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = src;
	}
}

/*
*
*	arr ==> ["main.c", "test.c", NULL]
*	type ==> "aowwwa"  a = append, o = override,  w = write
*/
/* 
====
*/
void		fill_token(t_token **head, char **arr, char* type)
{

	t_token  *token;
	int			i = -1;

	while (arr[++i])
	{
		token = (t_token *)malloc(sizeof(t_token));
		token->value = ft_strdup(arr[i]);
		token->type = type[i];
		token->next = NULL;
		append_lstk(head, token);
	}
}

void		output_token(t_token *token)
{
	while(token)
	{
		printf("%s====>%c\n", token->value, token->type);
		token = token->next;
	}
}

int			check_cmd(t_cmd *cmd)
{
	int		ret;
	int		i;

	ret = 0;
	i = -1;
	if (!cmd) // see the difference between this and the condition below
		return (0);
	if (cmd->args[0][0] != '\0')
	{
		ret = exec_builtin(cmd->args); // changes this line [04/10/21]
		if (ret != 2)
			return (ret);
		if (find_strenv("PATH")[0] == '\0')
			ret = 2;
		else
			ret = exec_bin(cmd->args);
	}
	//if (ret == 127)
		//return (file_dont_exist(cmd->args[0]));
	return (cmd_nfound(cmd->args[0]));
}

int			exec_cmd(t_cmd *cmd, t_token *token)
{
	int		fd_in;
	int		fd_out;
	int		ret;

	ret = 0;
	if (cmd->in_token->content || cmd->out_token->content)
	{
		fd_in = dup(0);
		fd_out = dup(1);
	}

	if (cmd->in_token->content || cmd->out_token->content)
		if (redirections(token))
			return (1);
	ret = check_cmd(cmd);
	//ret = 
	if (cmd->in_token->content || cmd->out_token->content)
	{
		dup2(fd_in, 0);
		dup2(fd_out, 1);
		close(fd_in);
		close(fd_out);
	}
	return (ret);
}

int			main_function(t_cmd *cmd, t_token *token)
{
	int		r;

	r = 0;
	// TODO:
	// check filter_all in the other folder;
	while (cmd)
	{
		if (cmd->is_piped)
			cmd = pipes(cmd);
		else
			r = exec_cmd(cmd, token);
		cmd = cmd->next;
	}
	return (r);
}

int			main(int argc, char **argv, char **env)
{
	//printf("\n\n");
	//t_cmd	*test = NULL;					// testing linked ist
	t_token *token = NULL; 
	//char	*red[] =  {"test.c", "test.txt", "test", NULL};
	//fill_token(&token, red, "aca");
	//output_token(token);
	init_env(argc, argv, env);
	char	*cmd[] = {"echo","hello", NULL};
	//char	*cmd1[] = {"wc",NULL};
	//exec_builtin(cmd1);
	//redirections(token); // in the exec_func dup fd_in and fd_out before opening redirections
	exec_bin(cmd);	
	//printf("%s\n", getenv("PWD"));
	//char	*cmd2[] = {"cd",NULL};
	//exec_builtin(cmd2);
	//test = fill_dummy(&test, cmd, cmd1);
	//pipes(test);
	return (0);
}