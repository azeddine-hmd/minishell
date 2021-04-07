/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:03:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/07 11:40:18 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	/*t_cmd	**cmds_lst;
	char	*syntax_err;*/
	t_buf	*input;
	char	c;


	setbuf(stdout, NULL);
	ms_init_terminal_data();
	ms_prompt();
	ms_bufinit(&input);
	while (read(STDIN_FILENO, &c, 1) == 1)
	{
		if (c == K_BS)
		{
			if (!ms_bufdel(input))
			{
				ms_curlef();
				ms_curdel();
			}
		}
		else if (c == K_CR)
		{
			ft_putc(c);
			//TODO: parsing
			//
		}
		else
		{
			ft_putc(c);
			ms_bufadd(input, c);
			(input->pos)++;
		}
	}
	return (0);
}
