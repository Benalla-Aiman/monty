#define _GNU_SOURCE
#include "monty.h"

int main(int argc, char **argv)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, fp) != -1)
    {
        char *opcode = strtok(line, " \n");
        char *arg = strtok(NULL, " \n");

        line_number++;

        if (opcode == NULL)
            continue;
        else if (strcmp(opcode, "push") == 0)
            _push(&stack, line_number, arg);
        else if (strcmp(opcode, "pall") == 0)
            _pall(&stack, line_number);
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    fclose(fp);

    return 0;
}
