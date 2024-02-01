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
