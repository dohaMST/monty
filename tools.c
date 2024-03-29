#include "monty.h"
#include <string.h>

/**
 * line_handler - a function that handles the line
 * @line: line from the getline function.
 * Return: handled string without a new line (\n).
 */
char *line_handler(char *line)
{
	int size, a = 0;

	while (line[a])
	{
		/*Find the first non-space character.*/
		if (line[a] != ' ')
		{
			line += a;
			break;
		}
		a++;
	}
	/*Calculate the length of the line.*/
	size = (int)strlen(line);
	/*handle the line if it is only a '\n'*/
	if (size == 1 && line[0] == '\n')
		return (line);
	/*handle the last character of the line if it is a newline character*/
	if (line[size - 1] == '\n')
		line[size - 1] = '\0';
	return (line);
}


/**
 * handle_opcode - a function that searches for an opcode in an array
 * @line: The opcode to search for.
 * @opArray: Array of instruction_t structures
 * Return: Index of the opcode
 */
int handle_opcode(char *line, instruction_t opArray[])
{
	int i = 0;

	/*Iterate through the opArray until we found the opcode*/
	while (i < 14 && strcmp(line, opArray[i].opcode) != 0)
	{
		i++;
	}

	/*return the index or -1*/
	return (i < 14 ? i : -1);
}

/**
 * handle_check_num - a function that checks if a string represents a valid int
 * @v: the value we wanna check
 * Return: 1 or 0
*/
int handle_check_num(char *v)
{
	char *x = v;

	/*check if the value is null*/
	if (!v)
		return (0);
	/*check if the first char is '-'*/
	if (*x == '-')
		x++;
	/*Iterate through the string chars*/
	while (*x != '\0')
	{
		if (*x >= '0' && *x <= '9')
			x++;
		else
			return (0);
	}
	/*return 1 if all the chars are digits*/
	return (1);
}
