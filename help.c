#include "monty.h"
/**
 * check_num - .
 * @value: .
 * Return: .
*/
int check_num(char *value)
{
	char *tmp = value;

	if (!value)
		return (0);
	if (*tmp == '-')
		tmp++;
	while (*tmp != '\0')
	{
		if (*tmp >= '0' && *tmp <= '9')
			tmp++;
		else
			return (0);
	}
	return (1);
}
/**
 * handle_new_line - Function handles the line that user enters
 * @line: Take the line from getline function
 * Return: The handled string without new line(\n)
*/
char *handle_new_line(char *line)
{
	int len, i = 0;

	while (line[i])
	{
		if (line[i] != ' ')
		{
			line += i;
			break;
		}
		i++;
	}
	len = (int)strlen(line);
	if (len == 1 && line[0] == '\n')
		return (line);

	len = (int)strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}
