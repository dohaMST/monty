#include "monty.h"
/**
 * handle_swap - a function that swaps the top elements of a list
 * @head: pointer to the head of the list/stack
 * @ln: line number of the opcode
 * Return: void
*/
void handle_swap(stack_t **head, unsigned int ln)
{
	int i;

	if (!(*head) || !((*head)->next))
	{
		handle_free_list(head);
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	i = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = i;
}
