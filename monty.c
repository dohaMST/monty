#define _POSIX_C_SOURCE 200809L
#include "monty.h"
char *val;

/**
* main - the main function
* @argc: the count of arguments
* @argv: the array of arguments
* Return: 0 for success
*/

int main(int argc, char const *argv[])
{
	char *line = NULL, *line_te, *instruction;
	size_t size = 0;
	ssize_t x;
	FILE *theFile;
	unsigned int i = 0;
	/*int idx;*/
	/*instruction_t opArray[] = {{"push", push}, {"pall", pall}, {"pint", pint},*/
	/*{"pop", pop}, {"swap", swap}, {"add", add},{"nop", nop},{"sub", sub}};*/
	stack_t *list = NULL;

	if (argc != 2)
	{

		/*argc_error();*/
		/*added*/
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	theFile = fopen(argv[1], "r");
	if (theFile == NULL)
	{
		/*file_error(argv[1]);*/
		/*added*/
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
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
		/*idx = opcode_(instruction, opArray);*/
		/*if (idx >= 0)*/
		/*	opArray[idx].f(&list, i);*/
		/*else*/
		/*{*/
		/*	handle_free_list(&list);*/
		/*	added*/
		/*	fprintf(stderr, "L%d: unknown instruction %s\n", i, line_te);*/
		/*	free(line);*/
		/*	exit(EXIT_FAILURE);*/

/*		}*/

		/*le it be a call function*/
		call_F(instruction, &list, i, line_te, line);
	}
	free(line);
	handle_free_list(&list);
	fclose(theFile);
	return (0);
}
