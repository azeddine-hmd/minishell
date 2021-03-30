#ifndef PARSER_H
# define PARSER_H

# include "../libft/libft.h"
# include "../linkedlist/linkedlist.h"
# include <stdio.h>

# define TRUE 1
# define FALSE 0

typedef struct	s_dll
{
	int				is_piped;
	int				fd;
	char			**args;
	char			*command;
	char			redirection;
	struct s_dll	*next;
	struct s_dll	*previous;
}				t_dll;

t_dll	*parse(const char *cmd_line);

// debugging prototype
void	print_dll_node(t_dll *dll_node);
void	print_all_dll_nodes(t_dll *head);

#endif
