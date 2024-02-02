#include "monty.h"

/**
 * handle_rotr - a function tha rotates a stack to the right
 * @head: double pointer to the head
 * @ln: line number of the opcode
 */

void handle_rotr(stack_t **head, __attribute__((unused))unsigned int ln)
{
	stack_t *curr;

	/*check if the stack or the top node is empty, or there's only one node*/
	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	curr = *head;

	while (curr->next != NULL)
		curr = curr->next;

	/*handle rotating the stack to the right*/
	curr->next = *head;
	curr->prev->next = NULL;
	curr->prev = NULL;
	(*head)->prev = curr;
	(*head) = curr;
}
