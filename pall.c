#include "monty.h"

void pall(stack_t *stack)
{
	if (!stack)
		return;
	while (stack)
	{
		printf("%d\n",stack->n);
		stack = stack->next;
	}
	while (stack->prev)
		stack = stack->prev
}
