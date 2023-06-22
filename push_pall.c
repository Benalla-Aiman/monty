#include "monty.h"

void _push(stack_t **stack, unsigned int line_number, char *num_str)
{
    int num;
    stack_t *new_node;

    num = atoi(num_str);
    if (num == 0 && num_str[0] != '0') /* Invalid argument or no argument at all */
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack != NULL)
        (*stack)->prev = new_node;
    *stack = new_node;
}

void _pall(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    (void) line_number;

    tmp = *stack;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}
