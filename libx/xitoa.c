#include "libx.h"

static long	numlen(long n)
{
	long i;

	i = 1;
	while ((n /= 10) != 0)
		i++;
	return (i);
}

static char	*zero_condition(void)
{
	char	*n;

	if (!(n = (char*)xmalloc(2)))
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
	if (!(strnum = (char*)xmalloc(len + 2)))
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

char		*xitoa(long n)
{
	char	*strnum;
	long	len;

	if (n == 0)
		return (zero_condition());
	if (n < 0)
		return (negative_condition((long)(n * -1)));
	len = numlen(n);
	if (!(strnum = (char*)xmalloc(len + 1)))
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
