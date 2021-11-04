#include "parser.h"

void	cmd_del(void *content)
{
	t_cmd	*casted;

	casted = (t_cmd*)content;
	lstclear(&(casted->in_token), token_del);
	lstclear(&(casted->out_token), token_del);
	xfree_str_array(casted->args);
}
