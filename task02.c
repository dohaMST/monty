#include "monty.h"

/**
 * handle_pop - a function that removes the top node of a list
 * @head: double pointer to the head
 * @ln: line number of the opcode
 */
void handle_pop(stack_t **head, unsigned int ln)
{
	stack_t *tmp;

	/*check if the stack is empty*/
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	/*move the head pointer to the next node*/
	*head = tmp->next;
	/*check if the new top node is not NULL*/
	if (*head != NULL)
		(*head)->prev = NULL;
	free(tmp);
}
