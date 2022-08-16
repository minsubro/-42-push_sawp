/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:28:52 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/15 19:29:01 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	s(t_stack *stack)
{
	t_list	*temp;
	int		n_temp;

	temp = stack->head;
	if (stack->size < 2)
		return ;
	n_temp = temp->n;
	temp->n = temp->right->n;
	temp->right->n = n_temp;
}

void	ss(t_stack_lst stack_lst)
{
	s(stack_lst.a_stack);
	s(stack_lst.b_stack);
}

void	p(t_stack *dst_stack, t_stack *src_stack)
{
	t_list	*src_temp;
	t_list	*dst_temp;

	if (src_stack->size == 0)
		return ;
	src_temp = src_stack->head;
	dst_temp = dst_stack->head;
	src_stack->head = src_temp->right;
	src_temp->right = dst_temp;
	if (dst_temp)
		dst_temp->left = src_temp;
	dst_stack->head = src_temp;
	(src_stack->size)--;
	(dst_stack->size)++;
	lst_link(dst_stack);
	lst_link(src_stack);
}
