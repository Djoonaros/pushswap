/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoonaros <djoonaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:21:30 by djoonaros         #+#    #+#             */
/*   Updated: 2023/05/09 03:21:31 by djoonaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	signcheck(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	digitcheck(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	twinfinder(const char *s1, const char *s2)
{
	int	cntr1;
	int	cntr2;

	cntr1 = 0;
	cntr2 = 0;
	if (s1[cntr1] == '+' && s2[cntr2] != '+')
		cntr1++;
	if (s1[cntr1] != '+' && s2[cntr2] == '+')
		cntr2++;
	while (s1[cntr1] && s2[cntr2] && s1[cntr1] == s2[cntr2])
	{
		cntr1++;
		cntr2++;
	}
	return (s1[cntr1] - s2[cntr2]);
}
