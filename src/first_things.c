/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoonaros <djoonaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:21:27 by djoonaros         #+#    #+#             */
/*   Updated: 2023/05/09 03:33:48 by djoonaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stackfiller(int ac, char **av)
{
	t_stack		*stack_a;
	long int	num;
	int			cntr;

	stack_a = 0;
	num = 0;
	cntr = 1;
	while (ac > cntr)
	{
		num = ft_atoi(av[cntr]);
		if (num > INT_MAX || num < INT_MIN)
			exiterror(&stack_a, 0);
		if (cntr == 1)
			stack_a = stacknew((int) num);
		else
			addbottom(&stack_a, stacknew((int) num));
		cntr++;
	}
	return (stack_a);
}

void	indexputter(t_stack *stack_a, int size)
{
	t_stack	*disboi;
	t_stack	*bigboi;
	int		value;

	while (--size > 0)
	{
		disboi = stack_a;
		value = INT_MIN;
		bigboi = NULL;
		while (disboi)
		{
			if (disboi->value == INT_MIN && disboi->index == 0)
				disboi->index = 1;
			if (disboi->value > value && disboi->index == 0)
			{
				value = disboi->value;
				bigboi = disboi;
				disboi = stack_a;
			}
			else
				disboi = disboi->next;
		}
		if (bigboi != NULL)
			bigboi->index = size;
	}
}
