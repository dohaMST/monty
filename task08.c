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

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		handle_free_list(head);
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	(*head) = (*head)->next;
	mul = (*head)->n * (*head)->prev->n;
	(*head)->n = mul;
	free((*head)->prev);
	(*head)->prev = NULL;
}
