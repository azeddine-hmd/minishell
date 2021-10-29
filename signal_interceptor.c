#include "minishell.h"

void	signal_interceptor(int sig)
{
	if (sig == SIGINT)
	{
		if (g_sign.child_running)
			return ;
		else
		{
			ft_putc('\n');
			ms_bufrst(g_sign.targ->buf);
			ms_prompt(g_sign.targ->cur->previous);
		}
	}
	else if (sig == SIGQUIT && g_sign.child_running)
	{
		write(1, "Quit: 3\n", 8);
		return ;
	}
}