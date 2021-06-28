#ifndef PARSER_H
# define PARSER_H
# include "../libft/libft.h"
# include "../linkedlist/linkedlist.h"
# include "../errors.h"
# include <stdio.h>

/*
** example: echo < text1.txt << text2.txt <<< y "Hello There"  > out1.txt >> out2.txt
** result:
** 		is_piped = false
**		fdin = "r:text1.txt;r:text2.txt;d:y"
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
	char			*original; // the previous cmds_str
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
char		*check_syntax_error(const char *cmdln);
t_bool		is_pipe_not_valid(const char *cmdln);

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
