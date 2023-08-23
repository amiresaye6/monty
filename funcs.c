#include "monty.h"

stack_t *top = NULL;

void push(int value) {
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

void pop() {
    stack_t *temp = top;

    if (top == NULL) {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    top = top->next;

    if (top != NULL) {
        top->prev = NULL;
    }

    free(temp);
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
int pint() {
    if (top == NULL) {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    return top->n;
}
