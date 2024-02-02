#include "monty.h"

/**
 * handle_free_list - a function that Frees the memory allocated for a list
 * @head: the head of the linked list
 * Return: void
*/

void handle_free_list(stack_t **head)
{
	stack_t *tmp2 = *head;
	stack_t *curr;

	/* Iterate through the list until we reach NULL*/
	while (tmp2 != NULL)
	{
		curr = tmp2;
		tmp2 = tmp2->next;
		/*free the memory of the current node*/
		free(curr);
	}
	/*set the head pointer to NULL*/
	*head = NULL;
}
