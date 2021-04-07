/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:09:23 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/07 11:22:28 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ms_prompt(void)
{
	printf(MS_PROMPT_COLOR);
	printf(MS_PROMPT);
	printf(COLORS_DEFAULT);
}

static void	enable_raw_mode(void)
{
	struct termios raw;

	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void		ms_init_terminal_data(void)
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
	enable_raw_mode();
}
