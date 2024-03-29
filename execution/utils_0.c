/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:08:59 by hboudhir          #+#    #+#             */
/*   Updated: 2021/11/05 15:46:32 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	**split_path(char **env)
{
	char	*tmp;
	char	**path;

	tmp = xsubstr(find_strenv("PATH", env), 5,
			ft_strlen(find_strenv("PATH", env)));
	path = xsplit(tmp, ':');
	xfree(tmp);
	return (path);
}

int	file_error(char *s)
{
	if (errno != 13)
	{
		write(2, "minishell: ", 11);
		write(2, s, strlen(s));
		write(2, ": No such file or directory\n", 28);
	}
	return (127);
}

char	*ft_strjoinch(char const *s1, char c)
{
	char	*new_str;
	size_t	i;
	size_t	s1_len;

	if (!s1 || !c)
		return (NULL);
	s1_len = ft_strlen(s1);
	new_str = safe_malloc(s1_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	*(new_str + i) = c;
	return (new_str);
}

int	ft_strstartw(char *s1, char *s2)
{
	int		i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

int	ft_strendw(char *s1, char *s2)
{
	int		i;

	i = -1;
	while (s1[++i])
		if (s1[i] == s2[0])
			if (ft_strcmp(s1 + i, s2) == 0)
				return (1);
	return (0);
}
