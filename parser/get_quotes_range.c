/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quotes_range.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 08:46:17 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/12 08:46:17 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	get_quote_pair_index(const char *s, char quote, int start_index)
{
	char	*quote_address;
	int		index;

	quote_address = ft_strchr(s + start_index, quote);
	if (is_null(quote_address))
		return (PAIR_NOT_FOUND);
	index = address_to_index(s, quote_address);
	return (index);
}

t_list	*get_quotes_range(const char *s)
{
	t_list	*head;
	t_range	*range;
	int		pair_index;
	int		i;

	head = NULL;
	i = 0;
	while (s[i])
	{
		if (ft_strchr(QUOTES, s[i]))
		{
			pair_index = get_quote_pair_index(s, s[i], i + 1);
			if (pair_index == PAIR_NOT_FOUND)
				break ;
			range = get_range(i, pair_index, s[i]);
			lstpush(&head, range);
			i = pair_index + 1;
		}
		else
			i++;
	}
	return (head);
}
