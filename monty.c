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
	FILE *theFile;
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
	handle_file(theFile, &list);
	handle_free_list(&list);
	fclose(theFile);
	return (0);
}
