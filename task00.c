#include "monty.h"


/**
 * handle_push - a function that adds a node to the stack
 * @list: a poiter to the stack
 * @ln: the line number of of the opcode
 */

void handle_push(stack_t **list, unsigned int ln)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int i, x;

	i = check_num(val);
	if ((!i))
	{
		free_list(&new_node);
		free_list(list);
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		exit(EXIT_FAILURE);
	}
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	x = atoi(val);
	new_node->n = x;
	new_node->prev = NULL;
	if (*list == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *list;
		(*list)->prev = new_node;
	}
	*list = new_node;
}
