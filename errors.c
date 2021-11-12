/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:07:49 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/09 21:07:49 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	set_raw_mode(t_bool enable)
{
	struct termios	tsettings;

	if (enable)
	{
		tcgetattr(0, &tsettings);
		tsettings.c_lflag &= ~(ECHO | ICANON);
		tcsetattr(0, 0, &tsettings);
	}
	else
		tcsetattr(0, 0, get_saved_tsettings());
}

void	shell_exit(int ret)
{
	set_raw_mode(false);
	deallocate();
	exit(ret);
}

void	shell_err(const char *error)
{
	printf(COLORS_RED);
	printf(ERR_SHELL_NAME);
	printf("%s\n", error);
	printf(COLORS_DEFAULT);
}

void	err(const char *error)
{
	printf(COLORS_RED);
	printf("Error: ");
	printf("%s\n", error);
	printf(COLORS_DEFAULT);
	shell_exit(1);
}

void	ferr(const char *err_format, const char *arg)
{
	printf(COLORS_RED);
	printf("Error: ");
	printf(err_format, arg);
	printf(COLORS_DEFAULT);
	shell_exit(1);
}
