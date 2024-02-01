#include "monty.h"
/**
 * push -.
 * @stack:.
 * @line_number: .
 * Return: .
*/
void push22(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	int num, number;

	num = check_num(val);
	if ((!num))
	{
		free_list(&new);
		free_list(stack);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	number = atoi(val);
	new->n = number;
	new->prev = NULL;
	if (*stack == NULL)
		new->next = NULL;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}
/**
 * pall - .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;

	temp = *stack;
	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint -Print the superiro value in stack .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		free_list(stack);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}
