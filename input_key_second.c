#include "minishell.h"

t_bool	ctrl_l_triggered(t_termarg *targ, char **env)
{
	char	*saved_buf_str;

	ft_putstr(targ->cap->ip);
	saved_buf_str = xstrdup(targ->buf->str);
	ms_bufrst(targ->buf);
	ms_prompt(getret(env));
	ms_bufrpc(targ->buf, saved_buf_str);
	ft_putstr(targ->buf->str);
	xfree(saved_buf_str);
	return (false);
}

t_bool	right_arrow_triggered(t_termarg *targ)
{
	targ->pos = 0;
	return (false);
}

t_bool	left_arrow_triggered(t_termarg *targ)
{
	targ->pos = 0;
	return (false);
}
