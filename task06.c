#include "monty.h"

/**
 * handle_sub - a function that substracts the first two elements of a list
 * @head: double pointer to the head of a the list
 * @ln: line number of opcode
 * Return: void
*/
void handle_sub(stack_t **head, unsigned int ln)
{
	int i;
	stack_t *tmp;

	/*check if the stack is less than 2 elements*/
	if (!(*head) || !((*head)->next))
	{
		handle_free_list(head);
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	i = (*head)->n;
	/*subtract the top element value from the second element value*/
	(*head)->next->n -= i;
	(*head)->next->prev = NULL;
	free(tmp);
	/*change the head pointer to the second element*/
	*head = (*head)->next;
}
