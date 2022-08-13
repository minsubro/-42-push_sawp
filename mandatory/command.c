/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:09:38 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/13 23:51:01 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_stack *stack, char a)
{
	if (stack->size < 2)
		return ;
	if (a == 'a' || a == 'b')
	{
		write(1, "r", 1);
		write(1, &a, 1);
		write(1, "\n", 1);
	}
	stack->tail = stack->head;
	stack->head = stack->head->right;
}

void	rr(t_stack_lst stack)
{
	r(stack.a_stack, 0);
	r(stack.b_stack, 0);
	write(1, "rr\n", 3);
}

void	rrab(t_stack *stack, char a)
{
	if (stack->size < 2)
		return ;
	if (a == 'a' || a == 'b')
	{
		write(1, "rr", 2);
		write(1, &a, 1);
		write(1, "\n", 1);
	}
	stack->head = stack->tail;
	stack->tail = stack->tail->left;
}

void	rrr(t_stack_lst stack)
{
	rrab(stack.a_stack, 0);
	rrab(stack.b_stack, 0);
	write(1, "rrr\n", 4);
}
