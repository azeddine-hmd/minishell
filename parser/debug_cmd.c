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
<<<<<<< HEAD:parser/parse_debugger.c
	int		i = 0;
||||||| 661ba87:parser/parse_debugger.c

=======

	fprintf(pa_log, "------start------\n");
>>>>>>> 3d75d692d2ff2fd27708c8787a0cf1150d0f32b9:parser/debug_cmd.c
	while (cmds)
	{
		cmd = (t_cmd*)cmds->content;
		print_cmd(cmd);
		cmds = cmds->next;
		i++;
	}
<<<<<<< HEAD:parser/parse_debugger.c
<<<<<<< HEAD
	printf("%d\n", i);
||||||| bf09544
=======
	fprintf(pa_log, "------end\n");
||||||| 661ba87:parser/parse_debugger.c
	fprintf(pa_log, "------end\n");
=======
	fprintf(pa_log, "------end------\n\n");
>>>>>>> 3d75d692d2ff2fd27708c8787a0cf1150d0f32b9:parser/debug_cmd.c
	fflush(NULL);
>>>>>>> 661ba8796051b80429c0d5ffbc13ae19d2df4470
}
