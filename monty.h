#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define TRUE 1
#define DELIM " \t\r\n\a\""
extern char *value;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*handle_free_list.c*/
/*void handle_free_list(stack_t **head);*/

/*handle_free_list2.c*/
void handle_free_list(stack_t **stack);
/*help.c*/
void call_F(char *inst, stack_t **st, unsigned int i, char *line_t, char *line);

/*function need to be edited*/
int opcode_(char *line, instruction_t opcode[]);
char *handle_new_line(char *line);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
int check_num(char *value);
void pint(stack_t **stack, unsigned int line_number);




#endif
