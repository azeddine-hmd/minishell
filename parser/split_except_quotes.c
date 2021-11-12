/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_except_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:30:11 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/12 10:30:11 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**split_except_quotes(const char *s, char c, t_list *quotes_range)
{
	char	**arr;
	char	*processed;
	int		i;

	processed = xstrdup(s);
	i = -1;
	while (processed[++i])
	{
		if (processed[i] == c && !inside_quotes(quotes_range, i, i, QUOTES))
			processed[i] = CHAR_PLACEHOLDER;
	}
	arr = xsplit(processed, CHAR_PLACEHOLDER);
	xfree(processed);
	return (arr);
}
