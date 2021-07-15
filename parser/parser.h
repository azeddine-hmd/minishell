#ifndef PARSER_H
# define PARSER_H
# include "../libft/libft.h"
# include "../libx/libx.h"
# include "../linkedlist/linkedlist.h"
# include "../errors.h"
# include <stdio.h>

# define TOKENS "> >> < << |"
# define QUOTES "'\""
# define NO_SYNTAX_ERROR NULL
# define PAIR_NOT_FOUND -1
# define QUOTE_ADDRESS_NOT_FOUND -1
# define CHAR_PLACEHOLDER -128

typedef struct s_token
{
	char			type;
	char			*value;
}t_token;

typedef struct s_cmd
{
	t_bool			is_piped;
	t_list			*in_token;
	t_list			*out_token;
	char			**args;
	int				ret;
	struct s_cmd	*next;
	struct s_cmd	*previous;
}t_cmd;

typedef struct s_cmdlst
{
	t_cmd			*cmds;
	char			*cmds_str;
	char			*original;
	int				ret;
	struct s_cmdlst	*next;
	struct s_cmdlst	*previous;
}t_cmdslst;

// debugging
void		fake_cmdslst(t_cmdslst **a_head);
void		print_all_cmdslst(t_cmdslst *head);
void		print_cmd(t_cmd *cmd);
void		print_all_cmds(t_cmd *head);
void		print_all_range(t_list *head);
void		print_all_tokens(t_list *head);
void		print_str_arr(char **str_arr);
void		print_str_lst(t_list *str_lst);

// parse
char		*parse(const char *cmdln, t_cmd **head, int prev_ret);
void		create_cmds(t_cmd **head, t_list *cmdln_lst);
char		**split_except_quotes(const char *s, char c, t_list *quotes_range);
t_list		*get_simplified_cmdln(const char *cmdln, int prev_ret);

// syntax error
char		*check_syntax_err(const char *cmdln, t_list *quotes_range); // refactor it later
t_bool		is_pipe_not_valid(const char *cmdln, t_list *quotes);

// quotes
t_bool		inside_quotes(t_list *range, int from, int to, const char *types);
t_list		*get_quotes_range(const char *s);

// range
void		range_del(void *content);
t_range		*get_range(int from, int to, char type);
t_bool		inside_range(t_range *range, int from, int to, char type);

// token
void		token_del(void *content);

// cmds
void		cmd_init(t_cmd *cmd, char **args, t_bool is_piped);
t_cmd		*get_cmd(const char *cmd_string, t_bool is_piped);
void		add_cmd(t_cmd **a_head, t_cmd *cmd);
t_cmd		*get_last_cmd(t_cmd *head);

// cmdslst
t_bool		has_previous(t_cmdslst *cmdslst);
t_cmdslst	*get_last_cmdslst(t_cmdslst *head);
void		add_cmdslst(t_cmdslst **a_head, t_cmdslst *cmdslst);
void		delete_cmdslst(t_cmdslst **a_head, t_cmdslst *target);
t_cmdslst	*get_cmdslst(t_cmd *cmd, char *cmds_str);

#endif
