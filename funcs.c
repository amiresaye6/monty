#include "monty.h"

stack_t *top = NULL;

/**
 * push - pushes teh value value into the stack
 * @value: int number to push into the stack
 *
 * Return: void
*/
void push(int value)
{
	stack_t *newNode = (stack_t *)malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = top;

	if (top != NULL)
	{
		top->prev = newNode;
	}

	top = newNode;
}

/**
 * pop - removes the top elment of the stack
 * @line_num: the number of the line operating
 *
 * Return: void
*/
void pop(int line_num)
{
	stack_t *temp = top;

	if (!top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		top = top->next;
		if (top != NULL)
		{
			top->prev = NULL;
		}

		free(temp);
	}
}

/**
 * pall - prints all the stack elments in LIFO style
 * Return: void
*/
void pall(void)
{
	stack_t *temp = top;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the top elment on the stack
 * @line_num: the number of the line operating
 *
 * Return: void
*/
void pint(int line_num)
{
	if (!top)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", top->n);
}

/**
 * swap - swaps the top two elments
 * @line_num: the number of the line operating
 *
 * Return: void
*/
void swap(int line_num)
{
	int temp;

	if (!top || !top->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = top->n;
		top->n = (top->next)->n;
		(top->next)->n = temp;
	}
}
