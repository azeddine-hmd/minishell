#include "parser.h"

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
	fflush(NULL);
}

void	print_all_cmds(t_list *cmds)
{
	t_cmd	*cmd;

	fprintf(pa_log, "------start------\n");
	while (cmds)
	{
		cmd = (t_cmd*)cmds->content;
		print_cmd(cmd);
		cmds = cmds->next;
	}
	fprintf(pa_log, "------end--------\n\n");
	fflush(NULL);
}
