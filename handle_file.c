#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * process_file - Reads lines from a file and processes them.
 * @theFile: File pointer.
 * @list: Pointer to the head of the stack.
 */
void handle_file(FILE *theFile, stack_t **list)
{
	char *line = NULL, *line_te, *instruction;
	size_t size = 0;
	ssize_t x;
	unsigned int i = 0;

	while (1)
	{
		i++;

		x = getline(&line, &size, theFile);
		if (x == -1)
			break;

		line_te = handle_new_line(line);
		if (strcmp(line_te, "\n") == 0 || line_te[0] == '#')
			continue;

		instruction = strtok(line_te, TOK_DELIM);
		val = strtok(NULL, TOK_DELIM);

		call_F(instruction, list, i, line_te, line);
	}

	free(line);
}
