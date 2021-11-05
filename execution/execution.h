/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:40:43 by hboudhir          #+#    #+#             */
/*   Updated: 2021/11/05 15:36:39 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <dirent.h>
# include <signal.h>
# include <sys/resource.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../libx/libx.h"
# include "../parser/parser.h"
# include "../minishell.h"

typedef struct s_env
{
	char	*key;
	char	*value;
}			t_env;

void		*safe_malloc(size_t size);
int			error_msg(char *error_msg, int fd, int exit_code);
char		*ft_strjoinch(char const *s1, char c);
int			ft_strstartw(char *s1, char *s2);
int			ft_strendw(char *s1, char *s2);
void		ft_freestrarr(char **arr);
char		*ft_strjoincl(char *s1, char *s2, int free_both);
char		**init_env(char **env);
int			env_len(char **env);
int			ft_builtin_env(char **env);
int			ft_builtin_pwd(char **env);
char		*find_strenv(char *str, char **env);
int			find_env(char *value, char **env);
char		**export_var(char *var, char *str, char **env);
char		**realloc_env(int size, char **env);
int			ft_builtin_export(char **args, char ***env);
char		*ft_pathjoin(char *s1, char *s2);
char		**delete_env(int index, char **env);
int			ft_builtin_unset(char **args, char ***env);
int			ft_builtin_cd(char **args, char ***env);
int			home_run(char ***env);
int			path_error(char *path);
char		*find_path(char *str, char **env);
int			redirections(t_cmd *cmd);
int			ft_builtin_echo(char **args);
int			file_dont_exist(char *file);
t_list		*pipes(t_list *cmds, char ***env);
int			exec_bin(char **cmd, char **env);
int			main_function(t_list *cmds, char ***env);
void		execute(t_list *cmds, char ***env);
int			exec_cmd(t_cmd *cmd, char ***env);
char		**split_path(char **env);
int			file_error(char *s);
int			ft_builtin_exit(char **cmd, int ret);
int			exec_path(char **cmd, char **env);
int			execute_p(char *p, char **cmd, char **env);
int			cmd_nfound(char *str);
int			exec_builtin(char **cmd, char ***env);
void		shell_exit(int ret);
void		ft_create_file(char *file, char *type);
void		check_dir(char *p);
int		open_failed(char *cmd);
#endif
