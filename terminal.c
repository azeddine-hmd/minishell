/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:09:23 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/17 14:05:51 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** formating and printing login prompt
*/

void		ms_prompt(void)
{
	printf(MS_PROMPT_COLOR);
	printf(MS_PROMPT);
	printf(COLORS_DEFAULT);
}

/*
** initializing all terminal capabilities
*/

static void	ms_capinit(t_cap **cap)
{
	*cap = (t_cap*)xmalloc(sizeof(t_cap));
	(*cap)->le = xstrdup(tgetstr("le", NULL));
	(*cap)->dc = xstrdup(tgetstr("dc", NULL));
}

static void	enable_raw_mode(void)
{
	struct termios raw;

	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
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
	enable_raw_mode();
	ms_capinit(cap);
	ms_bufinit(a_input);
}
