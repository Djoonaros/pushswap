/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoonaros <djoonaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:21:46 by djoonaros         #+#    #+#             */
/*   Updated: 2023/05/09 03:29:12 by djoonaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_stack *stack)
{
	while (stack->next != 0)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !issorted(*stack_a))
		swapa(stack_a);
	else if (size == 3)
		minisort(stack_a);
	else if (size > 3 && !issorted(*stack_a))
		sort(stack_a, stack_b);
}

int	main(int argcount, char **args)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argcount < 2)
		return (0);
	if (!correctinput(args))
		exiterror(0, 0);
	stack_b = 0;
	stack_a = stackfiller(argcount, args);
	size = stacksize(stack_a);
	indexputter(stack_a, size - 1);
	ft_push_swap(&stack_a, &stack_b, size);
	freestack(&stack_a);
	freestack(&stack_b);
	return (0);
}
