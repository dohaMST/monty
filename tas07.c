#include "monty.h"

/**
 * handle_div - Adds the top two elements of the stack.
 * @head: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void handle_div(stack_t **head, unsigned int ln)
{
	int div;

	/*check if the stack is less than 2 elements*/
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		handle_free_list(head);
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	/*Checking for division by zero*/
	if ((*head)->n == 0)
	{
		handle_free_list(head);
		fprintf(stderr, "L%d: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}
	(*head) = (*head)->next;
	/*calculate the division*/
	div = (*head)->n / (*head)->prev->n;
	/*update the value of the current node*/
	(*head)->n = div;
	free((*head)->prev);
	(*head)->prev = NULL;
}
