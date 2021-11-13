/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:03:43 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 23:03:43 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*get_envar(t_exinfo *exinfo, t_envindx *envi)
{
	char	*envar;

	envar = pa_getenv(exinfo->env, envi->name);
	if (is_null(envar))
	{
		return (xstrdup(""));
	}
	else
	{
		if (exinfo->apply)
			apply_token_change_to_string(envar);
		return (envar);
	}
}

// expand once to array: [0]=left_simplestring [1]=envar [2]=right_simplestirng
static char	**expand_once_array(t_exinfo *exinfo, t_envindx *envi, int start)
{
	char	**env_arr;
	t_list	*env_lst;
	char	*left_str;
	char	*right_str;

	env_lst = EMPTY_LIST;
	left_str = xstrsub(exinfo->str, start, envi->range->from - 1);
	if (not_null(left_str))
		lstpush(&env_lst, left_str);
	else
		lstpush(&env_lst, xstrdup(""));
	lstpush(&env_lst, get_envar(exinfo, envi));
	right_str = xstrsub(exinfo->str, envi->range->to + 1, exinfo->str_len - 1);
	if (not_null(right_str))
		lstpush(&env_lst, right_str);
	else
		lstpush(&env_lst, xstrdup(""));
	env_arr = string_list_to_string_array(env_lst);
	lstclear(&env_lst, str_del);
	return (env_arr);
}

static void	push_array(t_list **expanded_lst, char **env_arr)
{
	lstpush(expanded_lst, strdup(env_arr[0]));
	lstpush(expanded_lst, strdup(env_arr[1]));
}

// expand all environment variable into list
static t_list	*expand_to_lst(t_exinfo *exinfo)
{
	t_list		*expanded_lst;
	t_envindx	*envi;
	int			start;
	char		**env_arr;

	expanded_lst = EMPTY_LIST;
	start = 0;
	while (true)
	{
		envi = get_env_index(exinfo->str, start);
		if (is_null(envi))
			break ;
		if (inside_qts(exinfo->qts_rg, envi->range, "'"))
		{
			start = envi->range->to + 1;
			envindx_del(envi);
			continue ;
		}
		env_arr = expand_once_array(exinfo, envi, start);
		push_array(&expanded_lst, env_arr);
		exinfo->str = xstrdup(env_arr[2]);
		xfree_str_array(env_arr);
	}
	return (expanded_lst);
}

char	*expand(const char *str, char **env, t_bool apply)
{
	t_exinfo	exinfo;
	t_list		*expanded_lst;
	char		*expanded;

	if (!str)
		return (NULL);
	exinfo.str = xstrdup(str);
	exinfo.str_len = ft_strlen(str);
	exinfo.env = env;
	exinfo.apply = apply;
	exinfo.qts_rg = get_quotes_range(str);
	expanded_lst = expand_to_lst(&exinfo);
	lstclear(&(exinfo.qts_rg), range_del);
	if (is_null(expanded_lst))
		expanded = xstrdup(str);
	else
	{
		expanded = join_string_list_to_string(expanded_lst);
		lstclear(&expanded_lst, str_del);
	}
	return (expanded);
}
