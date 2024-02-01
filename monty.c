#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, ERR_USAGE);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, ERR_OPEN, argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(file, &stack);

	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}

/**
 * read_file - reads file
 * @file: file to read
 * @stack: pointer to stack
 */
void read_file(FILE *file, stack_t **stack)
{
	char *opcode;
	char *value;
	char *delim = " \n\t\r";
	char line[1024];
	unsigned int glob_lin = 0;

	while (fgets(line, 1024, file))
	{
		glob_lin++;
		opcode = strtok(line, delim);
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			value = strtok(NULL, delim);

			if (value == NULL || is_number(value) == 0 || value[0] == '#'
			|| *value == '#')
			{
				fprintf(stderr, ERR_PUSH, glob_lin);
				exit(EXIT_FAILURE);
			}
		}
		operationfunc(opcode, glob_lin, stack, value);
	}
}
