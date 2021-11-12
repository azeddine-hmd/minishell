/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envindx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:55:50 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 22:55:50 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool	is_valid_identifier(char c, int index)
{
	if (index == 0 && !ft_isalpha(c) && c != '_')
		return (false);
	else if (!ft_isalpha(c) && c != '_' && !ft_isdigit(c))
		return (false);
	else if (c == '\'' && c == '"')
		return (false);
	else if (c == '?')
		return (false);
	return (true);
}

void	envindx_del(void *content)
{
	t_envindx	*casted;

	casted = (t_envindx *)content;
	range_del(casted->range);
	xfree(casted->name);
	xfree(casted);
}

static char	*get_envname(const char *str, t_range *env_range)
{
	int		i;
	char	*name;

	i = env_range->from + 1;
	while (str[i] && is_valid_identifier(str[i], i - env_range->from + 1))
		i++;
	if (str[i] != '?' && i == env_range->from + 1)
		return (NULL);
	if (str[i] == '?')
		env_range->to = i;
	else
		env_range->to = i - 1;
	name = xsubstr(
			str, env_range->from + 1, env_range->to - env_range->from);
	return (name);
}

t_envindx	*get_env_index(const char *str, int start)
{
	t_envindx	*env_index;
	char		*found;

	env_index = (t_envindx *)xmalloc(sizeof(t_envindx));
	env_index->range = (t_range *)xmalloc(sizeof(t_range));
	env_index->name = xstrdup("");
	found = ft_strstr(str + start, "$");
	if (is_null(found))
	{
		envindx_del(env_index);
		return (NULL);
	}
	env_index->range->from = address_to_index(str, found);
	if (env_index->range->from == INDEX_NOT_FOUND)
	{
		envindx_del(env_index);
		return (NULL);
	}
	env_index->name = get_envname(str, env_index->range);
	if (is_null(env_index->name))
	{
		envindx_del(env_index);
		return (NULL);
	}
	return (env_index);
}
