#include "parser.h"

void	print_all_cmdslst(t_cmdslst *head)
{
	while (head)
	{
		fprintf(pa_log, "cmdline: %s\n", head->cmds_str);
		fprintf(pa_log, "original: %s\n", head->original);
		print_all_cmds(head->cmds);
		head = head->next;
	}
	fprintf(pa_log, "\n");
	fflush(NULL);
}

void	print_cmd(t_cmd *cmd)
{
	for (int i = 0; i < length(cmd->args); i++) {
		fprintf(pa_log, "args[%d]: %s\n", i, (cmd->args)[i]);
	}
	if (cmd->is_piped)
	{
		fprintf(pa_log, "is_piped: true\n");
	}
	else
	{
		fprintf(pa_log, "is_piped: false\n");
	}
	print_all_tokens(cmd->in_token);
	print_all_tokens(cmd->out_token);
	fprintf(pa_log, "\n");
	fflush(NULL);
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
	fprintf(pa_log, "------end\n");
	fflush(NULL);
}
