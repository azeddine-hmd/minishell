#ifndef PARSER_H
# define PARSER_H
# include "../libft/libft.h"
# include "../linkedlist/linkedlist.h"
# include <stdio.h>

typedef struct	s_cmd
{
	int				is_piped;
	int				fd;
	char			**args;
	char			*command;
	char			redirection;
	char			*error;
	struct s_cmd	*next;
	struct s_cmd	*previous;
}				t_cmd;

void	parse(const char *cmd_line, t_cmd **a_head, char **syntax_err);

// only for debugging
void	print_cmd(t_cmd *cmd);
void	print_all_cmds(t_cmd *head);

#endif
