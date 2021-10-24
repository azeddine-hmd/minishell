#ifndef PARSER_H
# define PARSER_H
# include "../libx/libx.h"
# include "../errors.h"
# include <stdio.h>

# define TOKENS "<< >> > < |"
# define IN_TYPE_TOKEN "<< <"
# define OUT_TYPE_TOKEN ">> >"
# define HEREDOC_TOKEN "<<"
# define PIPE "|"
# define QUOTES "'\""
# define FILE_PREFIX "/tmp/minishell-heredoc-"
# define HEREDOC_ERR "warning: here-document at line $LINE delimited by end-of-file (wanted `$DELIMETER')"

# define NO_SYNTAX_ERROR NULL
# define PAIR_NOT_FOUND -1
# define QUOTE_ADDRESS_NOT_FOUND -1
# define CHAR_PLACEHOLDER -128
# define FILE_PREMISSION 0666

// debugging
# define PARSE_DEBUG_LOG_PATH "/tmp/parse_log"
extern FILE *pa_log;

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

// debugging
void		print_cmd(t_cmd *cmd);
void		print_all_cmds(t_list *cmds);
void		print_all_range(t_list *head);
void		print_all_tokens(t_list *head);
void		print_str_arr(char **str_arr);
void		print_str_lst(t_list *str_lst);

// parse
char		*parse(const char *cmdln, t_list **cmds, char **env, int prev_ret);
void		create_cmds(t_list **cmds, t_list *cmdln_lst, char **env, int prev_ret);
char		**split_except_quotes(const char *s, char c, t_list *quotes_range);
t_list		*get_simplified_cmdln(const char *cmdln);
void		separate_quotes(t_list **cmdln_lst);
void		separate_tokens(t_list **cmdln_lst);
t_list		*add_token_to_cmd(t_list *cmdln_lst, t_cmd *cmd, t_list *element);
char		*expand(char *str, char **env, int prev_ret);
char		*pa_getenv(char **env, const char *name);

// syntax error
char		*check_syntax_err(t_list *cmdln_lst);

// quotes
t_bool		inside_quotes(t_list *range, int from, int to, const char *types);
t_list		*get_quotes_range(const char *s);
char		*strip_quotes(const char *s);

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

// tkindx
void		tkindx_del(void *content);

// cmd
void		cmd_del(void *content);

// envindx
void		envindx_del(void *content);
t_envindx	*get_env_index(const char *str, int start);

#endif
