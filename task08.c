#include "monty.h"

/**
 * handle_mul - a function that multiplies two first elements of a list
 * @head: double pointer to a the head of a list
 * @ln: line number of of the opcode
 * Return: void
 */
void handle_mul(stack_t **head, unsigned int ln)
{
	int mul;

	/*checkin if the stack is less than two elements*/
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		handle_free_list(head);
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	(*head) = (*head)->next;
	/*calculate the product of the first two elements*/
	mul = (*head)->n * (*head)->prev->n;
	/*update the value of the current node*/
	(*head)->n = mul;
	free((*head)->prev);
	(*head)->prev = NULL;
}
