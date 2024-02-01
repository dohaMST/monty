#define _POSIX_C_SOURCE 200809L
#include "monty.h"
char *val;

/**
 * main - Function that run our interpreter
 * @argc: Argument Count
 * @argv: Argument vector
 * Return: .
*/
int main(int argc, char const *argv[])
{
	char *line = NULL, *line_te, *instruction;
	size_t len = 0;
	ssize_t read;
	FILE *file;
	unsigned int compt = 0;
	int idx;
	instruction_t opcode[] = {{"push", push}, {"pall", pall}, {"pint", pint},
	{"pop", pop}, {"swap", swap}, {"add", add},{"nop", nop},{"sub", sub}};
	stack_t *stack = NULL;

	if (argc != 2)
	{

		/*argc_error();*/
		/*added*/
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		/*file_error(argv[1]);*/
		/*added*/
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		compt++;
		read = getline(&line, &len, file);
		if (read == -1)
			break;
		line_te = handle_new_line(line);
		if (strcmp(line_te, "\n") == 0 || line_te[0] == '#')
			continue;
		instruction = strtok(line_te, TOK_DELIM);
		val = strtok(NULL, TOK_DELIM);
		idx = opcode_(instruction, opcode);
		if (idx >= 0)
			opcode[idx].f(&stack, compt);
		else
		{
			free_list(&stack);
			/*instr_error(compt, line_te, line);*/
			/*added*/
			fprintf(stderr, "L%d: unknown instruction %s\n", compt, line_te);
			free(line);
			exit(EXIT_FAILURE);

		}
	}
	free(line);
	free_list(&stack);
	fclose(file);
	return (0);
}
