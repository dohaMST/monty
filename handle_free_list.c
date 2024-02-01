#include "monty.h"
/**
 * handle_free_list - a function that Frees the memory allocated for a list
 * @head: the head of the linked list
 * Return: void
*/
void handle_free_list(stack_t **head)
{
	stack_t *curr = *head;
	stack_t *tmp;

	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	*head = NULL;
}
