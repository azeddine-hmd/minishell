#include "minishell.h"

void	signal_interceptor(int sig)
{
	t_termarg *targ;

	targ = g_sign.targ;
	if (sig == SIGINT)
	{
		print_all_signal();
		if (g_sign.child_running)
		{
			return ;
		}
		else if (g_sign.heredoc_running)
		{
			g_sign.stop_heredoc = true;
			ft_putc('\n');
			ms_prompt(targ->cur->previous);
		}
		else
		{
			ft_putc('\n');
			ms_bufrst(targ->buf);
			ms_prompt(targ->cur->previous);
		}
	}
	else if (sig == SIGQUIT)
		return ;
}
