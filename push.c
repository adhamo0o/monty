#include "monty.h"
/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 * @value: Value to push onto the stack
 */
void push(stack_t **stack, unsigned int line_number, char *value)
{
	stack_t *new;

	(void)line_number;
	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, ERR_MALLOC);
		exit(EXIT_FAILURE);
	}

	new->n = atoi(value);
	new->prev = NULL;
	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * @value: unused parameter
 */
void pall(stack_t **stack, unsigned int line_number, char *value)
{
	stack_t *temp = *stack;

	(void)value;
	(void)line_number;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file where the opcode is found.
 * @value: Unused parameter.
 */
void pint(stack_t **stack, unsigned int line_number, char *value)
{
	(void)value;

	if (*stack == NULL)
	{
		fprintf(stderr, ERR_PINT, line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file where the opcode is found.
 * @value: Unused parameter.
 */
void pop(stack_t **stack, unsigned int line_number, char *value)
{
	(void)value;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, ERR_POP, line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file where the opcode is found.
 * @value: Unused parameter.
 */
void swap(stack_t **stack, unsigned int line_number, char *value)
{
	stack_t *temp;

	(void)value;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, ERR_SWAP, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	(*stack)->prev = temp;
	temp->next = *stack;
	temp->prev = NULL;
	if ((*stack)->next != NULL)
	{
		(*stack)->next->prev = *stack;
	}
	*stack = temp;
}
