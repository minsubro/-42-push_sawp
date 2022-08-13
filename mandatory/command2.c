/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 23:50:01 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/13 23:50:35 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *stack, char a)
{
	t_list	*temp;
	int		n_temp;

	temp = stack->head;
	if (stack->size < 2)
		return ;
	n_temp = temp->n;
	temp->n = temp->right->n;
	temp->right->n = n_temp;
	if (a == 'a' || a == 'b')
	{
		write(1, "s", 1);
		write(1, &a, 1);
		write(1, "\n", 1);
	}
}

void	ss(t_stack_lst stack_lst)
{
	s(stack_lst.a_stack, 0);
	s(stack_lst.b_stack, 0);
	write(1, "ss\n", 3);
}

void	p(t_stack *dst_stack, t_stack *src_stack, char a)
{
	t_list	*src_temp;
	t_list	*dst_temp;

	if (src_stack->size == 0)
		return ;
	write(1, "p", 1);
	write(1, &a, 1);
	write(1, "\n", 1);
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
