#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>
char *value;
/**
* main - the main function
* @argc: the count of arguments
* @argv: the array of arguments
* Return: 0 for success
*/
int main(int argc, char const *argv[])
{
	int idx;
	FILE *theFile;
	unsigned int i = 0;
	ssize_t x;
	char *line = NULL, *line_te, *opcode;
	size_t size = 0;
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
	stack_t *list = NULL;

	/* check if the number of commands is correct */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*open theFile and handle the existed errors */
	theFile = fopen(argv[1], "r");
	if (!theFile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*let it be a handle_line function*/
	while (TRUE)
	{
		i++; /*the counter of lines*/
		x = getline(&line, &size, theFile);
		/*in case we reached the EOF */
		if (x == -1)
			break;
		/*//handle the spaces and \n in the line*/
		line_te = handle_new_line(line);
		/*//skip empty lines and comments*/
		if (strcmp(line_te, "\n") == 0 || line_te[0] == '#')
			continue;

		/*extract the instruction and value*/
		opcode = strtok(line, DELIM);
		value = strtok(NULL, DELIM);
		/*let it be a call_function*/
		/*call_F(opcode, &list, i, line_te, line);*/
		idx = opcode_(opcode, opcodeArray);
		if (idx >= 0)
			opcodeArray[idx].f(&list, i);
		else
		{
			handle_free_list(&list);
			fprintf(stderr, "L%d: unknown instruction %s\n", i, line_te);
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	/*free all the allocated memory*/
	free(line);
	handle_free_list(&list);
	fclose(theFile);
	return (0);
}


