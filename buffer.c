/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:55:42 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/09 13:23:39 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** reset buffer
*/

void	ms_bufrst(t_buf *buf)
{
	buf->buf = xrealloc(buf->buf, buf->size, MS_BUFFER_SIZE);
	buf->size = MS_BUFFER_SIZE;
	ft_bzero(buf->buf, buf->size);
	buf->pos = 0;
	fprintf(ms_buflog, "buf: '%s'\n", buf->buf);
	fprintf(ms_buflog, "pos: '%zu'\n\n", buf->pos);
	fflush(ms_buflog);
}

/*
** delete character in buffer by replacing it with 0
** also moving cursor one character left
** nothing will happen if buffer is empty or param is NULL
*/

void	ms_bufdel(t_buf *buf, t_cap cap)
{
	if (!buf || buf->pos == 0)
	{
		fprintf(ms_buflog, "buf: '%s'\n", buf->buf);
		fprintf(ms_buflog, "pos: '%zu'\n\n", buf->pos);
		fflush(ms_buflog);
		return ;
	}
	else
	{
		(buf->pos)--;
		buf->buf[buf->pos] = 0;
		ms_chrdel(cap);
		fprintf(ms_buflog, "buf: '%s'\n", buf->buf);
		fprintf(ms_buflog, "pos: '%zu'\n\n", buf->pos);
		fflush(ms_buflog);
	}
}

/*
** add character to buffer and print it to stdout and handles buffer overflow
*/

void	ms_bufadd(t_buf *buf, char out)
{
	if (buf->pos == buf->size - 1)
	{
		buf->buf = xrealloc(buf->buf, buf->size, buf->size * 2);
		buf->size = buf->size * 2;
	}
	buf->buf[buf->pos] = out;
	(buf->pos)++;
	ft_putc(out);
	fprintf(ms_buflog, "buf: '%s'\n", buf->buf);
	fprintf(ms_buflog, "pos: '%zu'\n\n", buf->pos);
	fflush(ms_buflog);
}

/*
** initialize buffer memory
*/

void	ms_bufinit(t_buf **a_buf)
{
	t_buf *buf;

	if (!a_buf)
		error();
	*a_buf = (t_buf*)xmalloc(sizeof(t_buf));
	buf = *a_buf;
	buf->buf = (char*)xmalloc(MS_BUFFER_SIZE);
	buf->size = MS_BUFFER_SIZE;
	buf->pos = 0;
}
