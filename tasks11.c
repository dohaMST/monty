#include "monty.h"

/**
 * handle_pchar - a function that prints the Ascii code
 * @head: double pointer to the head
 * @ln: line number of the opcode
 * Return: void
 */
void handle_pchar(stack_t **head, unsigned int ln)
{
	int code;

	/*checking if the stack or top node is empty*/
	if (head == NULL || *head == NULL)
	{
		handle_free_list(head);
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	code = (*head)->n;
	/*checking if the int val is within the ASCII range*/
	if (code < 0 || code > 127)
	{
		handle_free_list(head);
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		exit(EXIT_FAILURE);
	}
	/*printing the ASCII character*/
	printf("%c\n", code);
}
