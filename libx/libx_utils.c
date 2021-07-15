#include "libx.h"

/*
** [Description]
** create new node with data in it.
**
** [Return Values]
** t_data*: a node with data in it.
** NULL: if data is NULL function returns NULL.
*/

t_data	*new_node(void *data)
{
	t_data	*node;

	if (!data)
		return (NULL);
	if (!(node = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

/*
** [Description]
** add data to list.
** this function handles all errors.
*/

void	add(t_data **head, void *data)
{
	t_data	*node;

	if (!data || !head)
		alloc_fail();
	if (!(node = new_node(data)))
		alloc_fail();
	lst_add_back(head, node);
}

/*
** [Description]
** add double pointers to the list.
*/

void	add_double_pointer(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		add(xmalloc_head(), ptr[i]);
	add(xmalloc_head(), ptr);
}

/*
** [Description]
** free double pointers
*/

void	xfree_double_pointer(char **ptr)
{
	int i;

	i = -1;
	while (ptr[++i])
		xfree(ptr[i]);
	xfree(ptr);
}

/*
** [Description]
** count size of nodes in the list.
**
** [Return Values]
** int: size of list.
*/

int		lst_size(t_data *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}
