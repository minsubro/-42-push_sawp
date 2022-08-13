/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 23:28:18 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/13 23:51:59 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	two_case(t_stack *stack)
{
	if (stack->head->n > stack->head->right->n)
		s(stack, 'a');
	return (1);
}

int	three_case(t_stack *stack)
{
	int		a;
	int		b;
	int		c;

	a = stack->head->n;
	b = stack->head->right->n;
	c = stack->head->right->right->n;
	if (a > b && b > c)
	{
		s(stack, 'a');
		rrab(stack, 'a');
	}
	else if (a > b && b < c && a > c)
		r(stack, 'a');
	else if (a < b && b > c && a > c)
		rrab(stack, 'a');
	else if (a > b && b < c && a < c)
		s(stack, 'a');
	else if (a < c && b > c && a < c)
	{
		s(stack, 'a');
		r(stack, 'a');
	}	
	return (1);
}

int	four_case(t_stack_lst stack)
{
	t_list	*temp;

	while (stack.a_stack->head->n != 0)
	{
		r(stack.a_stack, 'a');
	}
	p(stack.b_stack, stack.a_stack, 'b');
	three_case(stack.a_stack);
	p(stack.a_stack, stack.b_stack, 'a');
	temp = stack.a_stack->head;
	return (1);
}

int	five_case(t_stack_lst stack)
{
	t_list	*temp;

	while (stack.a_stack->size != 3)
	{
		if (stack.a_stack->head->n == 0 || stack.a_stack->head->n == 1)
			p(stack.b_stack, stack.a_stack, 'b');
		else
			r(stack.a_stack, 'a');
	}
	three_case(stack.a_stack);
	if (stack.b_stack->head->n < stack.b_stack->head->right->n)
		s(stack.b_stack, 'b');
	p(stack.a_stack, stack.b_stack, 'a');
	p(stack.a_stack, stack.b_stack, 'a');
	return (1);
}

int	exception_case(t_stack_lst stack)
{
	if (stack.a_stack->size == 2)
		return (two_case(stack.a_stack));
	if (stack.a_stack->size == 3)
		return (three_case(stack.a_stack));
	if (stack.a_stack->size == 4)
		return (four_case(stack));
	if (stack.a_stack->size == 5)
		return (five_case(stack));
	return (0);
}
