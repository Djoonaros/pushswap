/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoonaros <djoonaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:22:01 by djoonaros         #+#    #+#             */
/*   Updated: 2023/05/09 03:22:02 by djoonaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*buf;
	t_stack	*bottom;

	buf = *stack;
	*stack = (*stack)->next;
	bottom = getbottom(*stack);
	buf->next = 0;
	bottom->next = buf;
}

void	rotatea(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	rotateb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	rotateboth(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
