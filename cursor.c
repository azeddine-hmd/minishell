#include "minishell.h"

/*
** move cursor left and delete character inside cursor
*/

void	ms_chrdel(t_cap *cap)
{
	tputs(cap->le, 1, &ft_putc);
	tputs(cap->dc, 1, &ft_putc);
}

/*
** delete current line
*/

void	ms_lndel(t_cap *cap, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		ms_chrdel(cap);
	}
}
