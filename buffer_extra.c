#include "minishell.h"

void	ms_bufaddat(t_buf *buf, char out, size_t index)
{
	//TODO: useful if you want to handle left and right arrow
	if (buf->pos == buf->size - 1)
	{
		buf->str = xrealloc(buf->str, buf->size, buf->size * 2);
		buf->size = buf->size * 2;
	}
}
