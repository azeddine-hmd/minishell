#include "libx/libx.h"
#include "minishell.h"

t_bool	ctrl_l_triggered(t_termarg *targ)
{
	char	*saved_buf_str;

	//TODO: execute shell command without system function
	system("clear");

	saved_buf_str = xstrdup(targ->buf->str);
	ms_bufrst(targ->buf);
	ms_prompt(targ->cur->ret);
	ms_bufrpc(targ->buf, saved_buf_str);
	ft_putstr(targ->buf->str);
	xfree(saved_buf_str);
	return (false);
}

t_bool	right_arrow_triggered(t_termarg *targ)
{
#ifdef DEBUG
	fprintf(ms_log, "key: RIGHT_ARROW\n");
	fflush(ms_log);
#endif
	targ->pos = 0;
	//ignore
	return (false);
}

t_bool	left_arrow_triggered(t_termarg *targ)
{
#ifdef DEBUG
	fprintf(ms_log, "key: LEFT_ARROW\n");
	fflush(ms_log);
#endif
	targ->pos = 0;
	// ignore
	return (false);
}
