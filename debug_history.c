#include "minishell.h"

void	print_all_history(t_hist *history)
{
	while (history)
	{
		fprintf(pa_log, "cmdln_str: %s\n", history->cmdln_str);
		history = history->next;
	}
	fflush(NULL);
}
