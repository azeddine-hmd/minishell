/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_debugger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:05:23 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/05/04 17:23:10 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static t_cmd	*get_fake_cmd(char **s)
{
	static int	i = 0;
	t_cmd		*cmd;

	i++;
	*s = xstrjoin("command number ", ft_itoa(i));
	cmd = get_cmd(*s, false);
	return (cmd);
}

static t_cmdslst	*get_fake_cmdslst(void)
{
	t_cmdslst	*fake_cmdslst;
	t_cmd		*fake_cmd;
	char		*buf;

	fake_cmd = get_fake_cmd(&buf);
	fake_cmdslst = get_cmdslst(fake_cmd, buf);
	return (fake_cmdslst);
}

void	fake_cmdslst(t_cmdslst **a_head)
{
	int i;

	i = 0;
	while (i < 10)
	{
		add_cmdslst(a_head, get_fake_cmdslst());
		i++;
	}
}

void	print_all_cmdslst(t_cmdslst *head)
{
	while (head)
	{
		print_all_cmds(head->cmds);
		head = head->next;
	}
}

void	print_cmd(t_cmd *cmd)
{
	printf("-----COMMAND[%s]-----\n", cmd->args[0]);
	for (int i = 0; i < length(cmd->args); i++) {
		printf("args[%d]: \"%s\"\n", i, (cmd->args)[i]);
	}
	if (cmd->is_piped)
	{
		printf("is_piped: true\n");
	}
	else
	{
		printf("is_piped: false\n");
	}
	printf("fdin: '%s'\n", cmd->fdin);
	printf("fdout: '%s'\n", cmd->fdout);
	printf("\n");
}

void	print_all_cmds(t_cmd *head)
{
	while (head)
	{
		print_cmd(head);
		head = head->next;
	}
}
