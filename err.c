#include "monty.h"
/**
 * argc_error - void .
 * Return: .
*/
void argc_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * file_error - .
 * @file: .
 * Return: .
*/
void file_error(const char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}
/**
 * instr_error - .
 * @line: .
 * @line_copy: .
 * @cont: .
 * Return: .
*/
void instr_error(int cont, char *line_copy, char *line)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", cont, line_copy);
	free(line);
	exit(EXIT_FAILURE);
}
