#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element
 *       of the stack by the top element of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 * @value: Unused parameter
 */
void mod(stack_t **stack, unsigned int line_number, char *value)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, ERR_MOD, line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, ERR_DIV_2, line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number, value);
}

/**
 * pchar - Prints the char at the top of the stack, followed by a new line.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 * @value: Unused parameter
 */
void pchar(stack_t **stack, unsigned int line_number, char *value)
{
	(void)value;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, ERR_PCHAR2, line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 126)
	{
		fprintf(stderr, ERR_PCHAR, line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * pstr - Prints the string starting at the top of the stack,
 * 	  followed by a new line.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 * @value: Unused parameter
 */
void pstr(stack_t **stack, unsigned int line_number, char *value)
{
	stack_t *temp = *stack;
	(void)value;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	while (temp != NULL)
	{
		if (temp->n < 1 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 * @value: Unused parameter
 */
void rotl(stack_t **stack, unsigned int line_number, char *value)
{
	stack_t *temp = *stack;
	(void)value;
	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 * @value: Unused parameter
 */
void rotr(stack_t **stack, unsigned int line_number, char *value)
{
	stack_t *temp = *stack;
	(void)value;
	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
