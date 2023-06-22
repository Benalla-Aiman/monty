#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

void _push(stack_t **stack, unsigned int line_number, char *num_str);
void _pall(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
