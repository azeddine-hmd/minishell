#include "minishell.h"

void	signal_interceptor(int sig)
{
	t_termarg	*targ;

	targ = g_sign.targ;
	if (sig == SIGINT)
	{
		if (g_sign.child_running)
		{
			ft_putc('\n');
			return ;
		}
		else if (g_sign.heredoc_running)
		{
			g_sign.stop_heredoc = true;
			ft_putc('\n');
			*g_sign.env = export_var("?", "1", *g_sign.env);
			ms_prompt(getret(*g_sign.env));
		}
		else
		{
			ft_putc('\n');
			ms_bufrst(targ->buf);
			*g_sign.env = export_var("?", "1", *g_sign.env);
			targ->cur = get_last_history(targ->head);
			ms_prompt(getret(*g_sign.env));
		}
	}
	else if (sig == SIGQUIT && g_sign.child_running)
	{
		write(1, "Quit: 3\n", 8);
		return ;
	}
}
