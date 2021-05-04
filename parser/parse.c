/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:09:58 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/05/04 17:19:11 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse(const char *cmdln, t_cmd **a_head, char **synerr)
{
	t_cmd	*cmd;
	size_t	i;
	size_t	start;
	t_bool	is_next_pipe;
	char	*cmd_str;

	if (cmdln == NULL || !a_head || ft_strlen(cmdln) == 0)
		return ;
	*synerr = NULL;
	*a_head = NULL;
	start = 0;
	is_next_pipe = false;
	i = -1;
	while (cmdln[++i])
	{
		if (cmdln[i] != ';' && cmdln[i] != '|')
			continue ;
		cmd_str = xsubstr(cmdln, start, i - start);
		cmd = get_cmd(cmd_str, is_next_pipe);
		add_cmd(a_head, cmd);
		if (cmdln[i] == '|')
			is_next_pipe = true;
		else
			is_next_pipe = false;
		start = i + 1;
	}
	cmd_str = xsubstr(cmdln, start, ft_strlen(cmdln));
	cmd = get_cmd(cmd_str, is_next_pipe);
	add_cmd(a_head, cmd);
}
