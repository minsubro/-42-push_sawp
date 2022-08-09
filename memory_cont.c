/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:46:26 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/09 13:45:54 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_clear(t_stack *stack)
{
	t_list	*temp;
	t_list	*save;
	int		i;

	i = 0;
	temp = stack->head;
	while (i < stack->size)
	{
		save = temp->right;
		free(temp);
		temp = save;
		i++;
	}
	free(stack);
}

void	arr_free(t_list ***arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}