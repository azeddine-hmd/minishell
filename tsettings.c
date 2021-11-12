/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsettings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:05:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 22:05:35 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

struct termios	*get_saved_tsettings(void)
{
	static struct termios	*tsettings;

	if (!tsettings)
	{
		tsettings = (struct termios *)xmalloc(sizeof(struct termios));
		tcgetattr(0, tsettings);
	}
	return (tsettings);
}
