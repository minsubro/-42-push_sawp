/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:43:03 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/13 23:54:30 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack *a_stack)
{
	t_list	***arr;
	int		i;

	i = 0;
	arr = make_arr(a_stack);
	if (!arr)
		error();
	arr_sort(arr, 0, a_stack->size - 1);
	while (i < a_stack->size)
	{
		(*(arr[i]))->n = i;
		i++;
	}
	arr_free(arr, a_stack->size);
}

t_list	***make_arr(t_stack *stack)
{
	t_list	***arr;
	t_list	*temp;
	int		i;

	i = 0;
	arr = (t_list ***)malloc(sizeof(t_list **) * (stack->size + 1));
	if (!arr)
		return (NULL);
	temp = stack->head;
	while (i < stack->size)
	{
		arr[i] = (t_list **)malloc(sizeof(t_list *));
		if (!arr[i])
			error();
		*(arr[i]) = temp;
		temp = temp->right;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
