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
		{"push", handle_push},
		{"pall", handle_pall},
		{"pint", handle_pint},
		{"pop", handle_pop},
		{"swap", handle_swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub}
	};
	int idx = handle_opcode(inst, opcodeArray);

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