/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:49:52 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/12 11:49:52 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	apply_token_change(char *c)
{
	if (*c == '|')
		*c = -1;
	else if (*c == '<')
		*c = -2;
	else if (*c == '>')
		*c = -3;
	else if (*c == '$')
		*c = -4;
}

void	apply_token_change_to_string(char *s)
{
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		apply_token_change(&(s[i]));
}

void	revert_token_change(char *c)
{
	if (*c == -1)
		*c = '|';
	else if (*c == -2)
		*c = '<';
	else if (*c == -3)
		*c = '>';
	else if (*c == -4)
		*c = '$';
}

void	revert_token_change_to_string(char *s)
{
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		revert_token_change(&(s[i]));
}
