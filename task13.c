#include "monty.h"

/**
 * handle_rotl - a function that rotates 2 elements of a stack
 * @head: double pointer to head
 * @ln: line number of the opcode
 * Return: void
 */

void handle_rotl(stack_t **head, __attribute__((unused))unsigned int ln)
{
	stack_t *curr;

	/*Checking if the head or the top node is empty or has one node*/
	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	curr = *head;
	/*find the last node in the current stack*/
	while (curr->next != NULL)
		curr = curr->next;

	/*handle rotating the stack to the left*/
	curr->next = *head;
	(*head)->prev = curr;
	*head = (*head)->next;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}
