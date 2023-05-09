/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoonaros <djoonaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:21:13 by djoonaros         #+#    #+#             */
/*   Updated: 2023/05/09 03:51:08 by djoonaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	costcalculator(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*bufa;
	t_stack	*bufb;
	int		sizea;
	int		sizeb;

	bufa = *stack_a;
	bufb = *stack_b;
	sizea = stacksize(bufa);
	sizeb = stacksize(bufb);
	while (bufb)
	{
		bufb->costb = bufb->pos;
		if (bufb->pos > sizeb / 2)
			bufb->costb = ((sizeb - bufb->pos) * -1);
		bufb->costa = bufb->targetpos;
		if (bufb->targetpos > sizea / 2)
			bufb->costa = ((sizea - bufb->targetpos) * -1);
		bufb = bufb->next;
	}	
}

void	docheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*buf;
	int		cheapest;
	int		costa;
	int		costb;

	buf = *stack_b;
	cheapest = INT_MAX;
	while (buf)
	{
		if (absolute(buf->costa) + absolute(buf->costb) < absolute(cheapest))
		{
			cheapest = absolute(buf->costb) + absolute(buf->costb);
			costa = buf->costa;
			costb = buf->costb;
		}
		buf = buf->next;
	}
	move(stack_a, stack_b, costa, costb);
}
