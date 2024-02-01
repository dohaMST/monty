#include "monty.h"

/**
 * handle_add - a function that adds the two top elements of a list
 * @head: double pointer to the head of stack
 * @ln: line number of opcode
 * Return: void
*/
void handle_add(stack_t **head, unsigned int ln)
{
	int i;
	stack_t *tmp;

	if (!(*head) || !((*head)->next))
	{
		handle_free_list(head);
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	i = (*head)->n;
	(*head)->next->n += i;
	(*head)->next->prev = NULL;
	free(tmp);
	*head = (*head)->next;
}
