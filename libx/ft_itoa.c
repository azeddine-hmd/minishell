/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:59:25 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 19:59:25 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

static long	numlen(long n)
{
	long	i;

	i = 1;
	n /= 10;
	while (n != 0)
		i++;
	return (i);
}

static char	*zero_condition(void)
{
	char	*n;

	n = (char *)malloc(2);
	if (!n)
		return (NULL);
	*n = '0';
	*(n + 1) = '\0';
	return (n);
}

static char	*negative_condition(long n)
{
	char	*strnum;
	long	len;

	len = numlen(n);
	strnum = (char *)malloc(len + 2);
	if (!strnum)
		return (NULL);
	strnum = (char *)malloc(len + 2);
	if (!strnum)
		return (NULL);
	ft_bzero(strnum, len + 2);
	strnum[0] = '-';
	while (n)
	{
		strnum[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (strnum);
}

char	*ft_itoa(long n)
{
	char	*strnum;
	long	len;

	if (n == 0)
		return (zero_condition());
	if (n < 0)
		return (negative_condition((long)(n * -1)));
	len = numlen(n);
	strnum = (char *)malloc(len + 1);
	if (!strnum)
		return (NULL);
	ft_bzero(strnum, len + 1);
	while (n)
	{
		--len;
		strnum[len] = (n % 10) + '0';
		n /= 10;
	}
	return (strnum);
}
