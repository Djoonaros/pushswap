/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoonaros <djoonaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:22:11 by djoonaros         #+#    #+#             */
/*   Updated: 2023/05/09 03:38:38 by djoonaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	buf;

	if (!stack || !stack->next)
		return ;
	buf = stack->value;
	stack->value = stack->next->value;
	stack->next->value = buf;
	buf = stack->index;
	stack->index = stack->next->index;
	stack->next->index = buf;
}

void	swapa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

void	swapb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

void	swapboth(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
