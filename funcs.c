#include "monty.h"

stack_t *top = NULL;

void push(int value)
{
    stack_t *newNode = (stack_t *)malloc(sizeof(stack_t));
    if (newNode == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->n = value;
    newNode->prev = NULL;
    newNode->next = top;

    if (top != NULL) {
        top->prev = newNode;
    }

    top = newNode;
}
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
void pall()
{
    stack_t *temp = top;
    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
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
    top->n =(top->next)->n;
    (top->next)->n = temp;
    }
}
