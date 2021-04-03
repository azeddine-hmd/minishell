#include "parser.h"
#include <stdio.h>

void	print_cmd(t_cmd *cmd)
{
	printf("-----NODE ADDRESS: [%p]-----\n", &cmd);
	printf("command: \"%s\"\n", cmd->command);
	for (int i = 0; length(cmd->args); i++) {
		printf("args[%d]: \"%s\"\n", i, (cmd->args)[i]);
	}
	printf("is_piped: %d\n", cmd->is_piped);
	printf("fd: %d\n", cmd->fd);
	if (cmd->redirection == 0)
		printf("redirection: '\\0'\n");
	else
		printf("redirection: '%c'\n", cmd->redirection);
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
