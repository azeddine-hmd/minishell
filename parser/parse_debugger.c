/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_debugger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:05:23 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/13 15:15:01 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

void	print_cmd(t_cmd *cmd)
{
	printf("-----NODE ADDRESS: [%p]-----\n", &cmd);
	for (int i = 0; i < length(cmd->args); i++) {
		printf("args[%d]: \"%s\"\n", i, (cmd->args)[i]);
	}
	printf("is_piped: %d\n", cmd->is_piped);
	printf("fd: %s\n", cmd->fd);
	printf("redirection: '%s'\n", cmd->redirection);
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
