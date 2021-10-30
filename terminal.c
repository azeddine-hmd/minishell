#include "minishell.h"

/*
** formating and printing login prompt
*/

void		ms_prompt(int ret)
{
	if (ret == EXIT_SUCCESS)
		ft_putstr(MS_PROMPT_COLOR);
	else
		ft_putstr(MS_PROMPT_ERROR_COLOR);
	ft_putstr(MS_PROMPT);
	ft_putstr(COLORS_DEFAULT);
}

/*
** initializing all terminal capabilities
*/

static void	ms_capinit(t_cap **cap)
{
	*cap = (t_cap*)xmalloc(sizeof(t_cap));
	(*cap)->dc = xstrdup(tgetstr("dc", NULL));
	(*cap)->le = xstrdup(tgetstr("le", NULL));
	(*cap)->nd = xstrdup(tgetstr("nd", NULL));
	(*cap)->ip = xstrdup(tgetstr("ip", NULL));
}

static void	enable_raw_mode(t_bool enable)
{
	struct termios raw;

	if (enable)
	{
		tcgetattr(STDIN_FILENO, &raw);
		raw.c_lflag &= ~(ECHO | ICANON);
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
	}
}

/*
** initialize terminalinfo and handle terminal compatibility
*/

static void	ms_init_terminal_data(void)
{
	char 	*termtype;
	int		success;

	termtype = getenv("TERM");
	if (termtype == NULL)
		err(ERR_TERMTYPE);
	success = tgetent(NULL, termtype);
	if (success < 0)
		err(ERR_TERMACCESS);
	if (success == 0)
		ferr(ERR_TERMNOTDEFINED, termtype);
}

void		ms_setup(t_cap **cap, t_buf **a_input)
{
	ms_init_terminal_data();
	enable_raw_mode(true);
	ms_capinit(cap);
	ms_bufinit(a_input);
}
