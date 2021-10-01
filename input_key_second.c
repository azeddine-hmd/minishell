#include "minishell.h"

void	ctrl_l_triggered(t_termarg *targ)
{
	//TODO: execute shell command without system function
	system("clear");
	ms_bufrst(targ->buf);
	ms_prompt();
}
