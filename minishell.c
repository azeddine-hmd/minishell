#include "minishell.h"

void	init_terminal_data(void)
{
	char 	*termtype;
	char	term_buffer[2048];
	int		success;

	termtype = getenv("TERM");
	if (termtype == NULL)
		err(ERR_TERMTYPE);
	success = tgetent(term_buffer, termtype);
	if (success < 0)
		err(ERR_TERMACCESS);
	if (success == 0)
		ferr(ERR_TERMNOTDEFINED, termtype);
}

int		main(void)
{
	t_cmd	*cmd_list;
	char	*line;

	setbuf(stdout, NULL);
	init_terminal_data();
	while (true)
	{
		printf("minishell > ");
		get_next_line(STDIN_FILENO, &line);
		parse(line, &cmd_list);
		print_all_cmds(cmd_list);
		free(line);
	}
	return (0);
}
