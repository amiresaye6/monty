#include "monty.h"

/**
 * mod - adds the modelus of the second top elment by the top elment
 * @line_num: the number of the line currently running
 *
 * Return: void
 */
void mod(int line_num)
{
	int temp;

	if (!top || !top->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (top->next)->n % top->n;
		(top->next)->n = temp;
		pop(line_num);
	}
}

/**
 * pchar - prints the char val of the int in the top of the stack
 * @line_num: the number of the line currently running
 *
 * Return: void
 */
void pchar(int line_num)
{
	if (top->n > 255 || top->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
	else if (!top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", top->n);
}
