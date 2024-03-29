/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:11:57 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 20:11:57 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

static	int	get_length(char const *s, int c, int start)
{
	int	i;

	i = start;
	while (s[i] && s[i] != c)
		i++;
	return (i - start);
}

static	int	count_words(char const *s, char c)
{
	int	i;
	int	counter;
	int	is_word_completed;

	i = -1;
	counter = 0;
	is_word_completed = 1;
	while (s[++i])
	{
		if (s[i] != c && is_word_completed)
		{
			counter++;
			if (s[i + 1] != c)
				is_word_completed = 0;
		}
		if (s[i] == c)
			is_word_completed = 1;
	}
	return (counter);
}

static	char	*str_allocation(char const *s, char c, int start)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc(get_length(s, c, start) + 1);
	if (!str)
		return (0);
	i = start - 1;
	j = -1;
	while (s[++i] && s[i] != c)
		str[++j] = s[i];
	str[j + 1] = '\0';
	return (str);
}

static	char	**norminette_helper(char const *s, char c, char **str, int j)
{
	int			is_word_completed;
	int			i;

	i = -1;
	is_word_completed = 1;
	while (s[++i])
	{
		if (s[i] != c && is_word_completed)
		{
			str[++j] = str_allocation(s, c, i);
			if (!str[j])
			{
				while (j > 0)
					free(str[--j]);
				free(str);
				return (NULL);
			}
			if (s[i + 1] != c)
				is_word_completed = 0;
		}
		if (s[i] == c)
			is_word_completed = 1;
	}
	str[j + 1] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char		**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	return (norminette_helper(s, c, str, -1));
}
