/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 23:33:34 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/14 00:07:04 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_all(int *a, int *b, t_stack_lst stack)
{
	while (*a > 0 && *b > 0)
	{
		rr(stack);
		(*a)--;
		(*b)--;
	}
	while (*a < 0 && *b < 0)
	{
		rrr(stack);
		(*a)++;
		(*b)++;
	}
}

void	rotate_a(t_stack *stack, int *a)
{
	while (*a > 0)
	{
		r(stack, 'a');
		(*a)--;
	}
	while (*a < 0)
	{
		rrab(stack, 'a');
		(*a)++;
	}
}

void	rotate_b(t_stack *stack, int *a)
{
	while (*a > 0)
	{
		r(stack, 'b');
		(*a)--;
	}
	while (*a < 0)
	{
		rrab(stack, 'b');
		(*a)++;
	}
}

void	sort_set(t_stack *stack)
{
	int	i;

	i = min_idx(stack, 0);
	while (i > 0)
	{
		r(stack, 'a');
		i--;
	}
	while (i < 0)
	{
		rrab(stack, 'a');
		i++;
	}	
}
