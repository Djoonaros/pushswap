/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoonaros <djoonaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:22:14 by djoonaros         #+#    #+#             */
/*   Updated: 2023/05/09 03:22:15 by djoonaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freestack(t_stack **stack)
{
	t_stack	*buf;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		buf = (*stack)->next;
		free(*stack);
		*stack = buf;
	}
	*stack = NULL;
}

void	exiterror(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		freestack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		freestack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

long int	ft_atoi(const char *str)
{
	int				nb;
	int				sign;

	nb = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
		nb = nb * 10 + *str++ - '0';
	return (sign * nb);
}

void	ft_putstr(char *str)
{
	int	cntr;

	cntr = 0;
	while (str[cntr])
	{
		write(1, &str[cntr], 1);
		cntr++;
	}
}

int	absolute(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
