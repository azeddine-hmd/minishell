#include "minishell.h"

/*
** buffer replace with string
*/

void	ms_bufrpc(t_buf *buf, const char *s)
{
	size_t	new_size;

	new_size = ft_strlen(s) * 2 + 1;
	buf->str = xrealloc(buf->str, buf->size, new_size);
	buf->size = new_size;
	buf->pos = ft_strlen(s);
	ft_bzero(buf->str, buf->size);
	ft_memmove(buf->str, s, ft_strlen(s));
#ifdef DEBUG
	fprintf(ms_buflog, "buf: '%s'\n", buf->str);
	fprintf(ms_buflog, "pos: '%zu'\n\n", buf->pos);
	fflush(ms_buflog);
#endif
}

/*
** buffer reset
*/

void	ms_bufrst(t_buf *buf)
{
	buf->str = xrealloc(buf->str, buf->size, MS_BUFFER_SIZE);
	buf->size = MS_BUFFER_SIZE;
	ft_bzero(buf->str, buf->size);
	buf->pos = 0;
#ifdef DEBUG
	fprintf(ms_buflog, "buf: '%s'\n", buf->str);
	fprintf(ms_buflog, "pos: '%zu'\n\n", buf->pos);
	fflush(ms_buflog);
#endif
}

/*
** delete character in buffer by replacing it with 0
** also moving cursor one character left
** nothing will happen if buffer is empty or param is NULL
*/

void	ms_bufdel(t_buf *buf, t_cap *cap)
{
	if (!buf || buf->pos == 0)
	{
		fprintf(ms_buflog, "buf: '%s'\n", buf->str);
		fprintf(ms_buflog, "pos: '%zu'\n\n", buf->pos);
		fflush(ms_buflog);
		return ;
	}
	else
	{
		(buf->pos)--;
		buf->str[buf->pos] = 0;
		ms_chrdel(cap);
#ifdef DEBUG
		fprintf(ms_buflog, "buf: '%s'\n", buf->str);
		fprintf(ms_buflog, "pos: '%zu'\n\n", buf->pos);
		fflush(ms_buflog);
#endif
	}
}

/*
** add character to buffer and print it to stdout and handles buffer overflow
*/

void	ms_bufadd(t_buf *buf, char out)
{
	if (buf->pos == buf->size - 1)
	{
		buf->str = xrealloc(buf->str, buf->size, buf->size * 2);
		buf->size = buf->size * 2;
	}
	buf->str[buf->pos] = out;
	(buf->pos)++;
	(buf->last)++;
	ft_putc(out);
#ifdef DEBUG
	fprintf(ms_buflog, "buf: '%s'\n", buf->str);
	fprintf(ms_buflog, "pos: '%zu'\n\n", buf->pos);
	fflush(ms_buflog);
#endif
}

/*
** initialize buffer memory
*/

void	ms_bufinit(t_buf **a_buf)
{
	t_buf *buf;

	*a_buf = (t_buf*)xmalloc(sizeof(t_buf));
	buf = *a_buf;
	buf->str = (char*)xmalloc(MS_BUFFER_SIZE);
	buf->size = MS_BUFFER_SIZE;
}
