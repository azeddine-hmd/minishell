/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:16:57 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/12 10:16:57 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool	is_token(const char *s)
{
	char	**tokens;
	t_bool	found;
	int		i;

	found = false;
	tokens = xsplit(TOKENS, ' ');
	i = 0;
	while (i < length(tokens))
	{
		if (equal(s, tokens[i]))
			found = true;
		i++;
	}
	xfree_str_array(tokens);
	return (found);
}
