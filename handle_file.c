#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * process_file - Reads lines from a file and processes them.
 * @theFile: File pointer.
 * @list: Pointer to the head of the stack.
 */
void handle_file(FILE *theFile, stack_t **list)
{
	char *line = NULL, *cp_line, *instruction;
	size_t size = 0;
	ssize_t x;
	unsigned int i = 0;

	while (1)
	{
		i++;

		x = getline(&line, &size, theFile);
		if (x == -1)
			break;

		cp_line = handle_new_line2(line);
		if (strcmp(cp_line, "\n") == 0 || cp_line[0] == '#')
			continue;

		instruction = strtok(cp_line, " \t\r\n\a\"");
		val = strtok(NULL, " \t\r\n\a\"");

		call_F(instruction, list, i, cp_line, line);
	}

	free(line);
}
