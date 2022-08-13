/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 23:39:27 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/14 01:30:21 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*create_stack(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		error();
	new->head = NULL;
	new->size = 0;
	new->tail = NULL;
	return (new);
}

int	check(long long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}
