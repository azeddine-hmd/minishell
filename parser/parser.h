#ifndef PARSER_H
# define PARSER_H

# include "../libft/libft.h"
# include "../linkedlist/linkedlist.h"
# include <stdio.h>

# define TRUE 1
# define FALSE 0

typedef struct	s_cmd
{
	int				is_piped;
	int				fd;
	char			**args;
	char			*command;
	char			redirection;
	struct s_cmd	*next;
	struct s_cmd	*previous;
}				t_cmd;

t_cmd	*parse(const char *cmd_line);

// debugging prototype
void	print_cmd_node(t_cmd *dll_node);
void	print_all_cmd_nodes(t_cmd *head);

#endif
