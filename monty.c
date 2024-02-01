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
/*	char *line = NULL, *line_te, *instruction;*/
/*	size_t size = 0;*/
/*	ssize_t x;*/
	FILE *theFile;
/*	unsigned int i = 0;*/
	stack_t *list = NULL;

	if (argc != 2)
	{

		/*added*/
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	theFile = fopen(argv[1], "r");
	if (theFile == NULL)
	{
		/*added*/
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
/*	while (1)*/
/*	{*/
/*		i++;*/
/*		x = getline(&line, &size, theFile);*/
/*		if (x == -1)*/
/*			break;*/
/*		line_te = handle_new_line(line);*/
/*		if (strcmp(line_te, "\n") == 0 || line_te[0] == '#')*/
/*			continue;*/
/*		instruction = strtok(line_te, TOK_DELIM);*/
/*		val = strtok(NULL, TOK_DELIM);*/
		/*le it be a call function*/
/*		call_F(instruction, &list, i, line_te, line);*/
/*	}*/
	/*free(line);*/
	handle_file(theFile, &list);
	handle_free_list(&list);
	fclose(theFile);
	return (0);
}
