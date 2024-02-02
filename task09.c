#include "monty.h"

/**
 * handle_mod - a function that computes the modulus of the first two elements
 * @head: double pointer to the head of the list
 * @ln: line number of the opcode
 */
void handle_mod(stack_t **head, unsigned int ln)
{
	int mod;

	/*checking if the stack is less than 2 elms*/
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		handle_free_list(head);
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	/*cheking if denominator is 0*/
	if ((*head)->n == 0)
	{
		handle_free_list(head);
		fprintf(stderr, "L%d: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}
	(*head) = (*head)->next;
	/*calculate the modulo*/
	mod = (*head)->n % (*head)->prev->n;
	(*head)->n = mod;
	free((*head)->prev);
	(*head)->prev = NULL;
}
