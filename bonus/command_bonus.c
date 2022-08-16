/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:27:33 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/16 11:07:14 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	r(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->tail = stack->head;
	stack->head = stack->head->right;
}

void	rr(t_stack_lst stack)
{
	r(stack.a_stack);
	r(stack.b_stack);
}

void	rrab(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->head = stack->tail;
	stack->tail = stack->tail->left;
}

void	rrr(t_stack_lst stack)
{
	rrab(stack.a_stack);
	rrab(stack.b_stack);
}
