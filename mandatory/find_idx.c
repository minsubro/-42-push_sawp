/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_idx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 23:34:31 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/13 23:52:31 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mid_idx(t_stack *stack, int num)
{
	t_list	*temp;
	int		idx;

	idx = 0;
	temp = stack->head;
	while (idx < stack->size)
	{
		if (temp->n < num && temp->right->n > num)
			break ;
		idx++;
		temp = temp->right;
	}
	return (idx + 1);
}

int	stack_min(t_stack *stack)
{
	int		tmp;
	int		idx;
	t_list	*temp;

	idx = 0;
	temp = stack->head;
	tmp = temp->n;
	while (idx < stack->size)
	{
		if (tmp > temp->n)
			tmp = temp->n;
		temp = temp->right;
		idx++;
	}
	return (tmp);
}

int	min_idx(t_stack *stack, int min)
{
	t_list	*temp;
	int		idx;

	idx = 0;
	temp = stack->head;
	while (idx < stack->size)
	{
		if (temp->n == min)
			break ;
		temp = temp->right;
		idx++;
	}
	return (idx);
}

int	stack_max(t_stack *stack)
{
	t_list	*temp;
	int		tmp;
	int		idx;

	temp = stack->head;
	tmp = temp->n;
	idx = 0;
	while (idx < stack->size)
	{
		if (temp->n > tmp)
			tmp = temp->n;
		temp = temp->right;
		idx++;
	}
	return (tmp);
}

int	max_idx(t_stack *stack, int max)
{
	t_list	*temp;
	int		idx;

	idx = 0;
	temp = stack->head;
	while (idx < stack->size)
	{
		if (temp->n == max)
			break ;
		temp = temp->right;
		idx++;
	}
	return (idx + 1);
}
