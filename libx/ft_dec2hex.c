/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec2hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:31:47 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 20:31:47 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

static void	ft_strrev(char *str)
{
	int		lastindex;
	char	tmp;
	int		i;

	lastindex = ft_strlen(str) - 1;
	i = 0;
	while (i <= (lastindex / 2))
	{
		tmp = str[i];
		str[i] = str[lastindex - i];
		str[lastindex - i] = tmp;
		i++;
	}
}

static char	*hexer(int l)
{
	if (l > 15)
		return (NULL);
	if (l == 15)
		return (ft_strdup("f"));
	else if (l == 14)
		return (ft_strdup("e"));
	else if (l == 13)
		return (ft_strdup("d"));
	else if (l == 12)
		return (ft_strdup("c"));
	else if (l == 11)
		return (ft_strdup("b"));
	else if (l == 10)
		return (ft_strdup("a"));
	else
		return (ft_itoa(l));
}

char	*ft_dec2hex(size_t decimal)
{
	int		r;
	char	*final;
	char	*tmp;
	char	*tmp2;

	if (decimal < 16)
		return (hexer(decimal));
	r = decimal % 16;
	tmp = hexer(r);
	final = ft_strjoin("", tmp);
	free(tmp);
	decimal /= 16;
	while (decimal)
	{
		r = decimal % 16;
		tmp = hexer(r);
		tmp2 = final;
		final = ft_strjoin(final, tmp);
		free(tmp);
		free(tmp2);
	}
	ft_strrev(final);
	return (final);
}
