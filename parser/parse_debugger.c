#include "parser.h"

void	print_all_cmdslst(t_cmdslst *head)
{
	while (head)
	{
		fprintf(pa_log, "cmdln_str: %s\n", head->cmdln_str);
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

void	 print_all_cmds(t_list *cmds)
{
	t_cmd	*cmd;
	int		i = 0;
	while (cmds)
	{
		cmd = (t_cmd*)cmds->content;
		print_cmd(cmd);
		cmds = cmds->next;
		i++;
	}
<<<<<<< HEAD
	// The below printf was added to know how many commands were printed.
||||||| 39ea894
=======
<<<<<<< HEAD
>>>>>>> master
	printf("%d\n", i);
||||||| bf09544
=======
	fprintf(pa_log, "------end\n");
	fflush(NULL);
>>>>>>> 661ba8796051b80429c0d5ffbc13ae19d2df4470
}
