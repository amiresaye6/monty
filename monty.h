#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

extern stack_t *top;

void run_op(char op[], int line_num);
FILE *openFile(const char *filename, const char *mode);
void push(int i);
void pall(void);
void pint(int line_num);
void pop(int line_num);
void swap(int line_num);
void add(int line_num);
void nop(void);
void sub(int line_num);
void div_e(int line_num);
void mul(int line_num);
void mod(int line_num);
void pchar(int line_num);
#endif
