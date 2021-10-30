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
			export_var("?", "1", g_sign.env);
			ms_prompt(getret(g_sign.env));
		}
		else
		{
			ft_putc('\n');
			ms_bufrst(targ->buf);
			export_var("?", "1", g_sign.env);
			ms_prompt(getret(g_sign.env));
		}
	}
	else if (sig == SIGQUIT && g_sign.child_running)
	{
		write(1, "Quit: 3\n", 8);
		return ;
	}
}
