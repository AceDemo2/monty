#include "monty.h"

void _push(stack_t **stack, int n)
{
	stack_t *i;
	char *malerr;

	i = malloc(sizeof(stack_t));
	if (!i)
	{
		malerr = "Error: malloc failed";
		write(2, malerr, strlen(malerr));
		exit(EXIT_FAILURE);
	}
	i->n = n;
	if (*stack)
	{
		i->next = *stack;
		(*stack)->prev = i;
	}
	else
		i->next = NULL;
	*stack = i;
}	
