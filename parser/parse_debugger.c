#include "parser.h"

void	print_all_cmdslst(t_cmdslst *head)
{
	while (head)
	{
		printf("cmdline: '%s'\n", head->cmds_str);
		printf("original: '%s'\n", head->original);
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
	print_all_tokens(cmd->in_token);
	print_all_tokens(cmd->out_token);
	printf("\n");
}

void	print_all_cmds(t_list *cmds)
{
	t_cmd	*cmd;

	while (cmds)
	{
		cmd = (t_cmd*)cmds->content;
		print_cmd(cmd);
		cmds = cmds->next;
	}
}
