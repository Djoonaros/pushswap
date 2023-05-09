/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoonaros <djoonaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:21:34 by djoonaros         #+#    #+#             */
/*   Updated: 2023/05/09 03:21:35 by djoonaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	numbercheck(char *av)
{
	int	cntr;

	cntr = 0;
	if (signcheck(av[cntr]) && av[cntr + 1])
		cntr++;
	while (digitcheck(av[cntr]))
		cntr++;
	if (av[cntr] && !digitcheck(av[cntr]))
		return (0);
	return (1);
}

static int	antiduplicator(char **av)
{
	int	numa;
	int	numb;

	numa = 0;
	while (av[numa])
	{
		numb = 1;
		while (av[numb])
		{
			if (numa != numb && twinfinder(av[numa], av[numb]))
				return (1);
			numb++;
		}
	}
	return (0);
}

static int	zerofinder(char *av)
{
	int	cntr;

	cntr = 0;
	if (signcheck(av[cntr]))
		cntr++;
	while (av[cntr] == '0')
		cntr++;
	if (!av[cntr])
		return (0);
	return (1);
}

int	correctinput(char **av)
{
	int	cntr;
	int	zero;

	zero = 0;
	cntr = 0;
	while (av[cntr] && zero <= 1)
	{
		if (!numbercheck(av[cntr]))
			return (0);
		zero += zerofinder(av[cntr]);
		cntr++;
	}
	if (zero > 1)
		return (0);
	if (antiduplicator(av))
		return (0);
	return (1);
}
