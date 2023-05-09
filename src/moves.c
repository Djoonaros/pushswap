/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoonaros <djoonaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:21:51 by djoonaros         #+#    #+#             */
/*   Updated: 2023/05/09 03:53:44 by djoonaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_revrotboth(t_stack **a, t_stack **b, int *costa, int *costb)
{
	while (*costa < 0 && *costb < 0)
	{
		(*costa)++;
		(*costb)++;
		revrotboth(a, b);
	}
}

static void	do_rotboth(t_stack **a, t_stack **b, int *costa, int *costb)
{
	while (*costa > 0 && *costb > 0)
	{
		(*costa)--;
		(*costb)--;
		rotateboth(a, b);
	}
}

static void	do_rota(t_stack **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotatea(stack_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			revrota(stack_a);
			(*cost)++;
		}
	}
}

static void	do_rotb(t_stack **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotateb(stack_b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			revrotb(stack_b);
			(*cost)++;
		}
	}
}

void	move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_revrotboth(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotboth(stack_a, stack_b, &cost_a, &cost_b);
	do_rota(stack_a, &cost_a);
	do_rotb(stack_b, &cost_b);
	pusha(stack_a, stack_b);
}
