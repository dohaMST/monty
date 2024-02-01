#include <string.h>

/**
 * handle_new_line2 - Function handles the line that the user enters.
 * @line: Takes the line from the getline function.
 * Return: The handled string without a new line (\n).
 */
char *handle_new_line2(char *line)
{
	int len;

	/* Find the first non-space character.*/
	while (*line && *line == ' ')
		line++;

	/* Remove the trailing newline character, if present.*/
	len = (int)strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';

	return (line);
}

