/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 23:40:52 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/16 10:33:21 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b_all(t_stack_lst stack)
{
	while (3 < (stack.a_stack->size))
	{
		p(stack.b_stack, stack.a_stack, 'b');
	}
	if (stack.a_stack->size == 2)
		two_case(stack.a_stack);
	if (stack.a_stack->size == 3)
		three_case(stack.a_stack);
}

void	find_pivot(int size, int *pivot1, int *pivot2)
{
	*pivot1 = size / 3;
	*pivot2 = *pivot1 * 2;
}

void	a_to_b(t_stack_lst stack)
{
	int		pivot1;
	int		pivot2;
	int		size;

	size = stack.a_stack->size;
	find_pivot(stack.a_stack->size, &pivot1, &pivot2);
	while (size)
	{
		if (stack.a_stack->head->n <= pivot2)
		{
			p(stack.b_stack, stack.a_stack, 'b');
			if (stack.b_stack->head->n <= pivot1)
				r(stack.b_stack, 'b');
		}
		else
			r(stack.a_stack, 'a');
		size--;
	}
	a_to_b_all(stack);
}
