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
# include <readline/readline.h>
# include <readline/history.h>

/* My libft library */

//# include "libft/libft.h"	

/* 
	Below is Azeddine's libraries.
*/
# include "../libx/libx.h"
# include "../parser/parser.h"

//typedef struct s_token
//{
//	char			type;
//	char			*value;
//	struct s_token	*next;
//}				t_token;

//typedef struct	s_cmd		// PS: This is just a test struct for linked list.
//{
//	int				is_piped;
//	int				err;
//	int				pos;		// for debugging. (Inserting dummy data)
//	t_list			*in_token;
//	t_list			*out_token;
//	char			**args;     // array of arguments
//	struct s_cmd	*next;
//	struct s_cmd	*previous;
//}				t_cmd;




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
int			ft_builtin_pwd(void);
char		*find_strenv(char *str, char **env);
int			find_env(char *value, char **env);
void		export_var(char *var, char *str, char **env);
char		**realloc_env(int size, char **env);
int			ft_builtin_export(char **args, char **env);
char		*ft_pathjoin(char  *s1, char *s2);
void		delete_env(int	index, char **env);
int			ft_builtin_unset(char **args, char **env);
int			ft_builtin_cd(char **args, char **env);
int			home_run(char **env);
int			path_error(char *path);
char		*find_path(char *str,char **env);
int			redirections(t_token *token);
int			ft_builtin_echo(char **args);
int			file_dont_exist(char *file);
t_list		*pipes(t_list *cmds, char **env);
int			exec_bin(char **cmd, char **env);
int			main_function(t_list *cmds, char **env);
int			execute(t_list *cmds, char **env);
int			exec_cmd(t_cmd* cmd, char **env);
char		**g_env;
#endif

