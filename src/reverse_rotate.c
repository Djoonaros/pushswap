/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoonaros <djoonaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:21:58 by djoonaros         #+#    #+#             */
/*   Updated: 2023/05/09 03:40:00 by djoonaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	revrotate(t_stack **stack)
{
	t_stack	*buf;
	t_stack	*bot;
	t_stack	*secbot;

	bot = getbottom(*stack);
	secbot = getsecondbottom(*stack);
	buf = *stack;
	*stack = bot;
	(*stack)->next = buf;
	secbot->next = 0;
}

void	revrota(t_stack **stack_a)
{
	revrotate(stack_a);
	ft_putstr("ra\n");
}

void	revrotb(t_stack **stack_b)
{
	revrotate(stack_b);
	ft_putstr("rb\n");
}

void	revrotboth(t_stack **stack_a, t_stack **stack_b)
{
	revrotate(stack_a);
	revrotate(stack_b);
	ft_putstr("rrr\n");
}
