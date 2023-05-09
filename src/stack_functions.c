/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoonaros <djoonaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:22:06 by djoonaros         #+#    #+#             */
/*   Updated: 2023/05/09 03:37:11 by djoonaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacknew(int value)
{
	t_stack	*ret;

	ret = malloc(sizeof * ret);
	if (!ret)
		return (0);
	ret->value = value;
	ret->index = 0;
	ret->pos = -1;
	ret->targetpos = -1;
	ret->costa = -1;
	ret->costb = -1;
	ret->next = 0;
	return (ret);
}

int	stacksize(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	addbottom(t_stack **stack, t_stack *new)
{
	t_stack	*bottom;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	bottom = getbottom(*stack);
	bottom->next = new;
}

t_stack	*getbottom(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*getsecondbottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}
