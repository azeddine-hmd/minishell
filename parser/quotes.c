/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 04:42:27 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/12 04:42:27 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool	inside_quotes(t_list *range, int from, int to, const char *types)
{
	t_bool	found;
	t_range	*range_casted;

	found = false;
	while (range)
	{
		range_casted = (t_range *)range->content;
		if (ft_strchr(types, range_casted->type))
		{
			found = inside_range(range_casted, from, to, range_casted->type);
			if (found)
				return (true);
		}
		range = range->next;
	}
	return (found);
}

t_bool	inside_qts(t_list *range, t_range *target, const char *types)
{
	t_bool	found;
	t_range	*range_casted;
	int		from;
	int		to;

	if (!range)
		return (false);
	found = false;
	from = target->from;
	to = target->to;
	while (range)
	{
		range_casted = (t_range *)range->content;
		if (ft_strchr(types, range_casted->type))
		{
			found = inside_range(range_casted, from, to, range_casted->type);
			if (found)
				return (true);
		}
		range = range->next;
	}
	return (found);
}
