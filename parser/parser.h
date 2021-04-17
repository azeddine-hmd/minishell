/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:30:22 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/17 12:29:46 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../libft/libft.h"
# include "../linkedlist/linkedlist.h"
# include <stdio.h>

typedef struct s_cmd
{
	t_bool			is_piped;
	char			*fd;
	char			*redirection;
	char			**args;
	struct s_cmd	*next;
	struct s_cmd	*previous;
}t_cmd;

typedef struct s_cmdlst
{
	t_cmd			*cmds;
	char			*cmds_str;
	struct s_cmdlst	*next;
	struct s_cmdlst	*previous;
}t_cmdslst;

// debugging
void		fake_cmdslst(t_cmdslst **a_head);
void		print_all_cmdslst(t_cmdslst *head);
void		print_cmd(t_cmd *cmd);
void		print_all_cmds(t_cmd *head);

// parse.c
void		parse(const char *cmdln, t_cmd **a_head, char **synerr);

// cmds.c
void		cmd_init(t_cmd *cmd, char **args, t_bool is_piped);
t_cmd		*get_cmd(const char *cmd_string, t_bool is_piped);
void		add_cmd(t_cmd **a_head, t_cmd *cmd);
t_cmd		*get_last_cmd(t_cmd *head);

// cmdslst.c
t_cmdslst	*get_last_cmdslst(t_cmdslst *head);
void		add_cmdslst(t_cmdslst **a_head, t_cmdslst *cmdslst);
t_cmdslst	*get_cmdslst(t_cmd *cmd, char *cmds_str);

#endif
