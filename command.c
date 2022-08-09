/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:09:38 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/08 15:15:18 by minsukan         ###   ########.fr       */
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
		printf("s%c\n", a);
}

void	ss(t_stack_lst *stack_lst)
{
	s(stack_lst->a_stack, 0);
	s(stack_lst->b_stack, 0);
	printf("ss\n");
}

void	p(t_stack *dst_stack, t_stack *src_stack, char a)
{
	t_list	*src_temp;
	t_list	*dst_temp;

	printf("p%c\n", a);
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

void	r(t_stack *stack, char a)
{
	if (a == 'a' || a== 'b')
		printf("r%c\n", a);
	if (stack->size < 2)
		return ;
	stack->tail = stack->head;
	stack->head = stack->head->right;
}

void	rr(t_stack_lst *stack)
{
	r(stack->a_stack, 0);
	r(stack->b_stack, 0);
	printf("rr\n");
}

void	rrab(t_stack *stack, char a)
{
	if (a == 'a' || a== 'b')
		printf("rr%c\n", a);
	if (stack->size < 2)
		return ;
	stack->head = stack->tail;
	stack->tail = stack->tail->left;
}

void	rrr(t_stack_lst *stack)
{
	rrab(stack->a_stack, 0);
	rrab(stack->b_stack, 0);
	printf("rrr\n");
}