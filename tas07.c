#include "monty.h"

/**
 * handle_div - Adds the top two elements of the stack.
 * @head: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void handle_div(stack_t **head, unsigned int ln)
{
	int sum;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}
	(*head) = (*head)->next;
	sum = (*head)->n / (*head)->prev->n;
	(*head)->n = sum;
	free((*head)->prev);
	(*head)->prev = NULL;
}
