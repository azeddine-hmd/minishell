#ifndef PARSER_H
# define PARSER_H
# include "../libx/libx.h"
# include "../errors.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/errno.h>

# define TOKENS "<< >> > < |"
# define IN_TYPE_TOKEN "<< <"
# define OUT_TYPE_TOKEN ">> >"
# define HEREDOC_TOKEN "<<"
# define PIPE "|"
# define QUOTES "'\""
# define FILE_PREFIX "/tmp/minishell-heredoc-"

# define NO_SYNTAX_ERROR NULL
# define PAIR_NOT_FOUND -1
# define QUOTE_ADDRESS_NOT_FOUND -1
# define CHAR_PLACEHOLDER -128
# define FILE_PREMISSION 0666

typedef struct s_token
{
	char			*type;
	char			*value;
}t_token;

typedef struct s_cmd
{
	t_bool			is_piped;
	t_list			*in_token;
	t_list			*out_token;
	char			**args;
	int				ret;
}t_cmd;

typedef struct s_tkindx
{
	int				index;
	char			*token;
}t_tkindx;

typedef struct s_envindx
{
	t_range	*range;
	char	*name;
}t_envindx;

// entry
char		*parse(const char *cmdln, t_list **cmds, char **env);

// cmd
void		cmd_del(void *content);
void		create_cmds(t_list **cmds, t_list **cmdln_lst);
t_list		*get_simplified_cmdln(const char *cmdln);
t_list		*add_token_to_cmd(t_list **cmdln_lst, t_cmd *cmd, t_list *element);

// syntax error
char		*check_syntax_err(const char *cmdln);
char		*check_valid_files(t_list **cmds);
t_bool		is_valid_identifier(char c, int index);

// quotes
t_bool		inside_quotes(t_list *range, int from, int to, const char *types);
t_list		*get_quotes_range(const char *s);
char		**split_except_quotes(const char *s, char c, t_list *quotes_range);
char		*strip_quotes(const char *s);
void		strip_side_quotes(t_list *cmd_lst);

// range
void		range_del(void *content);
t_range		*get_range(int from, int to, char type);
t_bool		inside_range(t_range *range, int from, int to, char type);
int			get_range_len(t_range *range);
char		*token_from_range_type(char range_type);
char		token_to_range_type(const char *token);

// token
void		token_del(void *content);
t_bool		have_token(const char *str);
t_tkindx	*get_token_index(const char *str, int start);
t_list		*get_tokens_range(const char *str);
t_bool		is_token(const char *s);
void		separate_tokens(t_list **cmdln_lst);
void		apply_token_change(char *c);
void		apply_token_change_to_string(char *s);
void		revert_token_change(char *c);
void		revert_token_change_to_string(char *s);
void		restore_expanded_tokens(t_list *cmds);

// tkindx
void		tkindx_del(void *content);

// env
void		envindx_del(void *content);
t_envindx	*get_env_index(const char *str, int start);
int			getret(char **env);
char		*pa_getenv(char **env, const char *name);
char		*expand(const char *str, char **env, t_bool apply_tk_change);

#endif
