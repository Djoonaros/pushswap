/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoonaros <djoonaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:22:03 by djoonaros         #+#    #+#             */
/*   Updated: 2023/05/09 03:44:45 by djoonaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	maxindexfinder(t_stack *stack)
{
	int	ret;

	ret = stack->index;
	while (stack)
	{
		if (stack->index > ret)
			ret = stack->index;
		stack = stack->next;
	}
	return (ret);
}

void	minisort(t_stack **stack_a)
{
	int	max;

	if (issorted(*stack_a))
		return ;
	max = maxindexfinder(*stack_a);
	if ((*stack_a)->index == max)
		rotatea(stack_a);
	else if ((*stack_a)->next->index == max)
		revrota(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		swapa(stack_a);
}

static void	keepthree(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;
	int	cntr;

	size = stacksize(*stack_a);
	pushed = 0;
	cntr = 0;
	while (size > 6 && cntr < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pushb(stack_a, stack_b);
			pushed++;
		}
		else
			rotatea(stack_a);
		cntr++;
	}
	while (size - pushed > 3)
	{
		pushb(stack_a, stack_b);
		pushed++;
	}
}

static void	lowontop(t_stack **stack_a)
{
	int	minpos;
	int	size;

	size = stacksize(*stack_a);
	minpos = minindexposition(stack_a);
	if (minpos > size / 2)
	{
		while (minpos < size)
		{
			revrota(stack_a);
			minpos++;
		}
	}
	else
	{
		while (minpos > 0)
		{
			rotatea(stack_a);
			minpos++;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	keepthree(stack_a, stack_b);
	minisort(stack_a);
	while (*stack_b)
	{
		targetposition(stack_a, stack_b);
		costcalculator(stack_a, stack_b);
		docheapest(stack_a, stack_b);
	}
	if (issorted(*stack_a))
		lowontop(stack_a);
}
