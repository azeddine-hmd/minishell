/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:30:22 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/10 18:49:55 by ahamdaou         ###   ########.fr       */
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
	char			**args;
	char			*command;
	char			*redirection;
	char			*error;
	struct s_cmd	*next;
	struct s_cmd	*previous;
}t_cmd;

typedef struct s_cmdlst
{
	t_cmd	*cmds;
	t_cmd	*next;
	t_cmd	*previous;
}t_cmdslst;

// debugging
void	print_cmd(t_cmd *cmd);
void	print_all_cmds(t_cmd *head);

void	parse(const char *cmdli, t_cmd **a_head, char **synerr);

#endif
