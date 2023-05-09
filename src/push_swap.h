/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoonaros <djoonaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:21:23 by djoonaros         #+#    #+#             */
/*   Updated: 2023/05/09 03:49:18 by djoonaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				targetpos;
	int				costa;
	int				costb;
	struct s_stack	*next;
}	t_stack;

/* First Things */

t_stack		*stackfiller(int ac, char **av);
void		indexputter(t_stack *stack_a, int ac);

/* Input Check */

int			correctinput(char **av);
int			digitcheck(char c);
int			signcheck(char c);
int			twinfinder(const char *s1, const char *s2);

/* Sorting Algorithms */

int			issorted(t_stack *stack);
void		minisort(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

/* Position */

int			minindexposition(t_stack **stack);
void		targetposition(t_stack **stack_a, t_stack **stack_b);

/* Cost */

void		costcalculator(t_stack **stack_a, t_stack **stack_b);
void		docheapest(t_stack **stack_a, t_stack **stack_b);

/* Calculate Move */

void		move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Operations */

void		pusha(t_stack **stack_a, t_stack **stack_b);
void		pushb(t_stack **stack_a, t_stack **stack_b);
void		swapa(t_stack **stack_a);
void		swapb(t_stack **stack_b);
void		swapboth(t_stack **stack_a, t_stack **stack_b);
void		rotatea(t_stack **stack_a);
void		rotateb(t_stack **stack_b);
void		rotateboth(t_stack **stack_a, t_stack **stack_b);
void		revrotboth(t_stack **stack_a, t_stack **stack_b);
void		revrota(t_stack **stack_a);
void		revrotb(t_stack **stack_b);

/* Stack Functions */

t_stack		*getbottom(t_stack *stack);
t_stack		*getsecondbottom(t_stack *stack);
t_stack		*stacknew(int value);
void		addbottom(t_stack **stack, t_stack *new);
int			stacksize(t_stack	*stack);

/* Utility */

void		freestack(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			absolute(int nb);

/* Error */

void		exiterror(t_stack **stack_a, t_stack **stack_b);

#endif