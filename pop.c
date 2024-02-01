#include "monty.h"
/**
 * pop - remove the top element from the stack..
 * @stack: A pointer to a pointer of the stack_t structure. .
 * @line_number: .
 * Return: .
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!(*stack))
	{
		free_list(stack);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free_list(stack);
		return;
	}
	tmp = *stack;
	((*stack)->next)->prev = NULL;
	*stack = (tmp)->next;
	free(tmp);
}
