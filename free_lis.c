#include "monty.h"
/**
 * free_list - .
 * @stack: .
 * Return: .
*/
void free_list(stack_t **stack)
{
	stack_t *curr = *stack;
	stack_t *free_me;

	while (curr != NULL)
	{
		free_me = curr;
		curr = curr->next;
		free(free_me);
	}
	*stack = NULL;
}
