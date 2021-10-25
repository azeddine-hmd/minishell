#include "minishell.h"

void	signal_interceptor(int sig)
{
	//TODO: impelment
	(void)sig;
	print_all_signal();
}
