#include "minishell.h"

void	print_keys(char input)
{
#ifdef DEBUG
	if (input == K_ENTER)
		fprintf(ms_log, "key: ENTER\n");
	else if (input == K_BS)
		fprintf(ms_log, "key: Backspace\n");
	else
		fprintf(ms_log, "key: %c\n", input);
	fflush(ms_log);
#endif
}

void	print_buffer(t_buf *buf)
{
#ifdef DEBUG
	fprintf(ms_buflog, "buf: '%s'\n", buf->str);
	fprintf(ms_buflog, "pos: '%zu'\n", buf->pos);
	fprintf(ms_buflog, "last: '%zu'\n\n", buf->last);
	fflush(ms_buflog);
#endif
}
