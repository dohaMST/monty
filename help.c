#include "monty.h"

/**
 * call_F - Executes the opcode based on the instruction.
 * @inst: The opcode instruction.
 * @st: the head of the stack.
 * @i: Line number.
 * @line_t: Processed line.
 * @line: Original line.
 */
void call_F(char *inst, stack_t **st, unsigned int i, char *line_t, char *line)
{
	instruction_t opcodeArray[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		/*{"pop", pop},*/
		/*{"swap", swap},*/
		/*{"add", add},*/
		/*{"nop", nop},*/
		/*{"sub", sub}*/
	};
	int idx = opcode_(inst, opcodeArray);

	if (idx >= 0)
		opcodeArray[idx].f(st, i);
	else
	{
		handle_free_list(st);
		fprintf(stderr, "L%d: unknown instruction %s\n", i, line_t);
		free(line);
		exit(EXIT_FAILURE);
	}
}
/**
 * check_num - .
 * @value: .
 * Return: .
*/
int check_num(char *value)
{
	char *tmp = value;

	if (!value)
		return (0);
	if (*tmp == '-')
		tmp++;
	while (*tmp != '\0')
	{
		if (*tmp >= '0' && *tmp <= '9')
			tmp++;
		else
			return (0);
	}
	return (1);
}
