#include "monty.h"

/**
 * handle_pop - a function that removes the top node of a list
 * @head: double pointer to the head
 * @ln: line number of the opcode
 */
void handle_pop(stack_t **head, unsigned int ln)
{
	stack_t *tmp;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = tmp->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(tmp);
}
