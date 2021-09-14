#include "parser.h"

void	tkindx_del(void *content)
{
	t_tkindx	*token_index;

	token_index = (t_tkindx *)content;
	xfree(token_index->token);
	xfree(token_index);
}
