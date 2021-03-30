#include "parser.h"

void	print_dll_node(t_dll *dll_node)
{
	printf("-----NODE ADDRESS: %p-----\n", &dll_node);
	printf("command: \"%s\"\n", dll_node->command);
	for (int i = 0; length(dll_node->args); i++) {
		printf("args[%d]: \"%s\"\n", i, (dll_node->args)[i]);
	}
	printf("is_piped: %d\n", dll_node->is_piped);
	printf("fd: %d\n", dll_node->fd);
	printf("redirection: %c\n", dll_node->redirection);
	printf("\n");
}

void	print_all_dll_nodes(t_dll *head)
{
	while (head)
	{
		print_dll_node(head);
		head = head->next;
	}
}
