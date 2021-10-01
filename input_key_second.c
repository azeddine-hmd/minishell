#include "libx/libx.h"
#include "minishell.h"

void	ctrl_l_triggered(t_termarg *targ)
{
	char	*saved_buf_str;

	//TODO: execute shell command without system function
	system("clear");
	saved_buf_str = xstrdup(targ->buf->str);
	ms_bufrst(targ->buf);
	ms_prompt();
	ms_bufrpc(targ->buf, saved_buf_str);
	ft_putstr(targ->buf->str);
	xfree(saved_buf_str);
}
