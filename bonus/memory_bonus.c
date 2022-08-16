/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:19:07 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/15 20:22:31 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	str_clear(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

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
