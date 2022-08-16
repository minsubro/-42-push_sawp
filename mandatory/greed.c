/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 23:31:13 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/16 10:34:07 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_a_pos(t_stack *stack, int num)
{
	int		idx;

	if (stack->size < 2)
		return (0);
	if (num < stack_min(stack))
		idx = min_idx(stack, stack_min(stack));
	else if (num > stack_max(stack))
		idx = max_idx(stack, stack_max(stack));
	else
		idx = mid_idx(stack, num);
	if (idx >= (stack->size + 1) / 2)
		return ((stack->size - idx) * -1);
	return (idx);
}

int	ft_compare(int a, int b, int a_pos, int b_pos)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a_pos < 0)
		a_pos = -a_pos;
	if (b_pos < 0)
		b_pos = -b_pos;
	if (a + b > a_pos + b_pos)
		return (1);
	else
		return (0);
}	

void	get_min_rotate(t_stack_lst stack, int *a, int *b)
{
	int		a_pos;
	int		b_pos;
	int		idx;
	t_list	*temp;

	idx = 0;
	temp = stack.b_stack->head;
	while (idx < stack.b_stack->size)
	{
		a_pos = find_a_pos(stack.a_stack, temp->n);
		if (idx >= (stack.b_stack->size + 1) / 2)
			b_pos = (stack.b_stack->size - idx) * -1;
		else
			b_pos = idx;
		if (idx == 0 || ft_compare(*a, *b, a_pos, b_pos))
		{
			*a = a_pos;
			*b = b_pos;
		}
		temp = temp->right;
		idx++;
	}
}

void	greed(t_stack_lst stack)
{
	int		a;
	int		b;

	while (stack.b_stack->size)
	{
		a = 0;
		b = 0;
		get_min_rotate(stack, &a, &b);
		rotate_all(&a, &b, stack);
		rotate_a(stack.a_stack, &a);
		rotate_b(stack.b_stack, &b);
		p(stack.a_stack, stack.b_stack, 'a');
	}
}
