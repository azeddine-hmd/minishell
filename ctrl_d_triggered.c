/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d_triggered.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:23:55 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/09 19:23:55 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ctrl_d_triggered(t_termarg *targ)
{
	if (ft_strlen(targ->buf->str) == 0)
		return (true);
	return (false);
}
