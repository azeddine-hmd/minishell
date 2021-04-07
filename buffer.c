/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:55:42 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/07 11:40:12 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** delete character in buffer by replacing it with 0, also handles errors.
** if param is NULL, we assume behaviour is undefined
**
** return: <int> indicates whether buffer is empty or not
*/

int		ms_bufdel(t_buf *input)
{
	if (input->pos == 0)
	{
		return (TRUE);
	}
	else
	{
		input->buf[input->pos - 1] = 0;
		(input->pos)--;
		return (FALSE);
	}
}

/*
** add character to buffer and handles buffer overflow
*/

void	ms_bufadd(t_buf *input, char c)
{
	if (input->pos == input->size - 1)
	{
		input->buf = xrealloc(input->buf, input->size, input->size * 2);
		input->size = input->size * 2;
	}
	input->buf[input->pos] = c;
	(input->pos)++;
}

/*
** initialize buffer memory
*/

void	ms_bufinit(t_buf **a_input)
{
	t_buf *input;

	if (!a_input)
		error();
	*a_input = (t_buf*)xmalloc(sizeof(t_buf));
	input = *a_input;
	input->buf = (char*)xmalloc(MS_BUFFER_SIZE);
	input->size = MS_BUFFER_SIZE;
	input->pos = 0;
}
