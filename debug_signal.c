#include "minishell.h"

void print_all_signal(void)
{
#ifdef DEBUG
	fprintf(ms_signallog, "\n");
	if (g_sign.child_running == false)
		fprintf(ms_signallog, "child_running: false\n");
	else
		fprintf(ms_signallog, "child_running: true\n");
	if (g_sign.heredoc_running == false)
		fprintf(ms_signallog, "heredoc_running: false\n");
	else
		fprintf(ms_signallog, "heredoc_running: true\n");
	if (g_sign.stop_heredoc == false)
		fprintf(ms_signallog, "stop_heredoc: false\n");
	else
		fprintf(ms_signallog, "stop_heredoc: true\n");
	fprintf(ms_signallog, "\n");
	fflush(ms_signallog);
#endif
}
