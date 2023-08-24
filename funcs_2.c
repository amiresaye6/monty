#include "monty.h"

/**
 * add - addes the top two elmens on the stack
 * @line_num: the number of the line currently running
 *
 * Return: void
*/
void add(int line_num)
{
	int temp;

	if (!top || !top->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = top->n + (top->next)->n;
		(top->next)->n = temp;
		pop(line_num);
	}
}

/**
 * nop - does nothing
 *
 * Return: void
*/
void nop(void)
{
	/*do nothing*/
}

/**
 * sub - subtracts the top two elmens on the stack
 * @line_num: the number of the line currently running
 *
 * Return: void
*/
void sub(int line_num)
{
	int temp;

	if (!top || !top->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (top->next)->n - top->n;
		(top->next)->n = temp;
		pop(line_num);
	}
}

/**
 * div_e - devides the top two elmens on the stack
 * @line_num: the number of the line currently running
 *
 * Return: void
*/
void div_e(int line_num)
{
	int temp;

	if (!top || !top->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (top->next)->n / top->n;
		(top->next)->n = temp;
		pop(line_num);
	}
}

/**
 * mul - multiblyes the top two elmens on the stack
 * @line_num: the number of the line currently running
 *
 * Return: void
*/
void mul(int line_num)
{
	int temp;

	if (!top || !top->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = top->n * (top->next)->n;
		(top->next)->n = temp;
		pop(line_num);
	}
}
