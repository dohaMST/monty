#include "monty.h"
/**
 * pint -Print the superiro value in stack .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		handle_free_list(stack);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}
