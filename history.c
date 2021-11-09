/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:43:12 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/09 21:43:12 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	has_previous(t_hist *history)
{
	if (is_null(history->previous))
		return (false);
	else
		return (true);
}

t_hist	*get_last_history(t_hist *history)
{
	while (history->next != NULL)
	{
		history = history->next;
	}
	return (history);
}

void	add_history(t_hist **head, t_hist *history)
{
	t_hist	*last_history;

	if (*head == NULL)
	{
		*head = history;
	}
	else
	{
		last_history = get_last_history(*head);
		last_history->next = history;
		history->previous = last_history;
	}
}
