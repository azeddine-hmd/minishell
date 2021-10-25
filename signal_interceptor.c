#include "minishell.h"

void	signal_interceptor(int sig)
{
	if (sig == SIGINT)
	{
		print_all_signal();
		if (g_sign.heredoc_running)
		{
			//TODO: implmenet
		}
		else if (g_sign.child_running)
		{
			//TODO: impelement
		}
	}
}
