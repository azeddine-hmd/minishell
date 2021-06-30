#ifndef PARSER_H
# define PARSER_H
# include "../libft/libft.h"
# include "../libx/libx.h"
# include "../linkedlist/linkedlist.h"
# include "../errors.h"
# include <stdio.h>

# define NO_SYNTAX_ERROR NULL
# define QUOTES "'\""
# define PAIR_NOT_FOUND -1
# define QUOTE_ADDRESS_NOT_FOUND -1

/*
** example: echo < text1.txt "Hello There"  > out1.txt >> out2.txt
** result:
** 		is_piped = false
**		fdin = "r:text1.txt"
**		fdout = "w:out1.txt;a:out2.txt"
**		args = { "echo", "Hello There", NULL }
*/

typedef struct s_cmd
{
	t_bool			is_piped;
	char			*fdin;
	char			*fdout;
	char			**args;
	struct s_cmd	*next;
	struct s_cmd	*previous;
}t_cmd;

typedef struct s_cmdlst
{
	t_cmd			*cmds;
	char			*cmds_str;
	char			*original;
	struct s_cmdlst	*next;
	struct s_cmdlst	*previous;
}t_cmdslst;

// debugging
void		fake_cmdslst(t_cmdslst **a_head);
void		print_all_cmdslst(t_cmdslst *head);
void		print_cmd(t_cmd *cmd);
void		print_all_cmds(t_cmd *head);

// parse.c
char		*parse(const char *cmdln, t_cmd **head);
char		*check_syntax_error(const char *cmdln, t_list *quotes_range);
t_bool		is_pipe_not_valid(const char *cmdln, t_list *quotes_range);
void		create_cmds(const char *cmdln, t_cmd **head);
t_list		*get_quotes_range(const char *s);
t_bool		inside_quotes(t_list *range, int from, int to, const char *types);

// range
void		range_del(void *content);
t_range		*get_range(int from, int to, char type);
t_bool		inside_range(t_range *range, int from, int to, char type);

// cmds.c
void		cmd_init(t_cmd *cmd, char **args, t_bool is_piped);
t_cmd		*get_cmd(const char *cmd_string, t_bool is_piped);
void		add_cmd(t_cmd **a_head, t_cmd *cmd);
t_cmd		*get_last_cmd(t_cmd *head);

// cmdslst.c
t_cmdslst	*get_last_cmdslst(t_cmdslst *head);
void		add_cmdslst(t_cmdslst **a_head, t_cmdslst *cmdslst);
void		delete_cmdslst(t_cmdslst **a_head, t_cmdslst *target);
t_cmdslst	*get_cmdslst(t_cmd *cmd, char *cmds_str);

#endif
