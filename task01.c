#include "monty.h"
/**
 * handle_pint - a function that prints the top node of the list
 * @head: double pointer to top node of the list
 * @ln: line number of the opcode.
 */
void handle_pint(stack_t **head, unsigned int ln)
{
	/*check if the stack is empty*/
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	/*print the value at the top of the stack*/
	printf("%d\n", (*head)->n);
}
