#include "minishell.h"

void	signal_interceptor(int sig)
{
	t_termarg	*targ;
	char		**env;

	targ = g_sign.targ;
	env = *g_sign.env;
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
			*g_sign.env = export_var("?", "1", env);
			ms_prompt(getret(env));
		}
		else
		{
			ft_putc('\n');
			ms_bufrst(targ->buf);
			*g_sign.env = export_var("?", "1", env);
			ms_prompt(getret(env));
		}
	}
	else if (sig == SIGQUIT && g_sign.child_running)
	{
		write(1, "Quit: 3\n", 8);
		return ;
	}
}
