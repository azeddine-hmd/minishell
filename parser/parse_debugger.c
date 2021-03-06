#include "parser.h"

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

void	print_all_cmds(t_cmd *head)
{
	while (head)
	{
		print_cmd(head);
		head = head->next;
	}
}
