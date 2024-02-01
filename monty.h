#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#define TOK_DELIM " \t\r\n\a\""
extern char *val;
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

extern stack_t *head;
/*char *handle_new_line(char *line);*/
/*int opcode_(char *line, instruction_t opcode[]);*/
char **generate_argv(char *line);
/*void push2(stack_t **stack, unsigned int line_number);*/
/*void pall(stack_t **stack, unsigned int line_number);*/
/*void pint(stack_t **stack, unsigned int line_number);*/
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div1(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint_end(stack_t **head, int n);

int check_num(char *value);
void free_list(stack_t **stack);
/***/
/*handle_free_list.c*/
void handle_free_list(stack_t **head);

/*handle call_function.c*/
void call_F(char *inst, stack_t **st, unsigned int i, char *line_t, char *line);

/*handle_file.c*/
void handle_file(FILE *theFile, stack_t **list);

/*tools.c*/
char *line_handler(char *line);
int handle_opcode(char *line, instruction_t opArray[]);

/*task00.c*/
void handle_push(stack_t **list, unsigned int ln);
void handle_pall(stack_t **stack, unsigned int line_number);

/*task01.c*/
void handle_pint(stack_t **head, unsigned int ln);




#endif
