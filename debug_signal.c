#include "minishell.h"

void print_all_signal(void)
{
#ifdef DEBUG
	if (g_sign.child_running == false)
		fprintf(ms_signallog, "child_running: false\n");
	else
		fprintf(ms_signallog, "child_running: true\n");
	fprintf(ms_signallog, "\n");
	fflush(ms_signallog);
#endif
}
