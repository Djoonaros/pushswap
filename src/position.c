/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoonaros <djoonaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:21:53 by djoonaros         #+#    #+#             */
/*   Updated: 2023/05/09 03:45:36 by djoonaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	position(t_stack **stack)
{
	t_stack	*buf;
	int		position;

	buf = *stack;
	position = 0;
	while (buf)
	{
		buf->pos = position;
		buf = buf->next;
		position++;
	}
}

int	minindexposition(t_stack **stack)
{
	t_stack	*buf;
	int		indexmin;
	int		positionmin;

	buf = *stack;
	indexmin = INT_MAX;
	position(stack);
	positionmin = buf->pos;
	while (buf)
	{
		if (buf->index < indexmin)
		{
			indexmin = buf->index;
			positionmin = buf->pos;
		}
		buf = buf->next;
	}
	return (positionmin);
}

static int	target(t_stack **stack, int index, int targetindex, int targetpos)
{
	t_stack	*buf;

	buf = *stack;
	while (buf)
	{
		if (buf->index > index && buf->index < targetindex)
		{
			targetindex = buf->index;
			targetpos = buf->pos;
		}
		buf = buf->next;
	}
	if (targetindex != INT_MAX)
		return (targetpos);
	buf = *stack;
	while (buf)
	{
		if (buf->index < targetindex)
		{
			targetindex = buf->index;
			targetpos = buf->pos;
		}
		buf = buf->next;
	}
	return (targetpos);
}

void	targetposition(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*buf;
	int		targetpos;

	buf = *stack_b;
	position(stack_a);
	position(stack_b);
	targetpos = 0;
	while (buf)
	{
		targetpos = target(stack_a, buf->index, INT_MAX, targetpos);
		buf->targetpos = targetpos;
		buf = buf->next;
	}
}
