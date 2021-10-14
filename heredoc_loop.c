#include "libx/libx.h"
#include "minishell.h"

void	hd_prompt(void)
{
	ft_putstr(COLORS_BLUE);
	ft_putstr(MS_HEREDOC_PROMPT);
	ft_putstr(COLORS_DEFAULT);
}

char		*heredoc_loop(t_termarg *targ, const char *delimiter)
{
	t_list	*lines_lst;
	char	*fcontent;
	char	*saved_bufstr;

	lines_lst = NULL;
	saved_bufstr = xstrdup(targ->buf->str);
	ms_bufrst(targ->buf);
	hd_prompt();
	while (read(STDIN_FILENO, &(targ->input), 1) == 1)
	{
		if (targ->input == K_BS)
			backspace_triggered(targ);
		else if (targ->input == K_ENTER)
		{
			if (!ft_strcmp(targ->buf->str, delimiter))
			{
				ft_putc(targ->input);
				break ;
			}
			else
			{
				ft_putc(targ->input);
				ft_lstadd_back(&lines_lst, ft_lstnew(xstrdup(targ->buf->str)));
				ms_bufrst(targ->buf);
				hd_prompt();
			}
		}
		else if (targ->input == K_ESC)
			targ->pos++;
		else if (targ->pos == 1 && targ->input == K_OSB)
			targ->pos++;
		else if (targ->pos == 2 && targ->input == K_A)
			// ignore
			;
		else if (targ->pos == 2 && targ->input == K_B)
			// ignore
			;
		else if (targ->pos == 2 && targ->input == K_C)
			// ignore
			;
		else if (targ->pos == 2 && targ->input == K_D)
			// ignore
			;
		else if (targ->pos == 2)
			targ->pos = 0;
		else if (targ->input == K_CTRL_D)
		{
			if (ctrl_d_triggered(targ, true))
				break ;
		}
		else if (targ->input == K_CTRL_L)
			// ignore
			;
		else if (
				targ->input == K_CTRL_I ||
				targ->input == K_CTRL_H ||
				targ->input == K_CTRL_K
				)
		{
			// ignore
		}
		else
		{
#ifdef DEBUG
			fprintf(ms_log, "key: %d\n", targ->input);
			fflush(ms_log);
#endif
			ms_bufadd(targ->buf, targ->input);
			ft_putc(targ->input);
			targ->pos = 0;
		}
	}
	ms_bufrpc(targ->buf, saved_bufstr);
	xfree(saved_bufstr);
	fcontent = join_string_list_with_nl(lines_lst);
	ft_lstclear(&lines_lst, str_del);
	return (fcontent);
}
