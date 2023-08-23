#include "monty.h"

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

void nop()
{
    /*do nothing*/
}
