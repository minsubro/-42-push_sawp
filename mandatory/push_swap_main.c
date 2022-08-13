/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:08:23 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/14 00:04:18 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	push_swap(t_stack_lst stack)
{	
	a_to_b(stack);
	greed(stack);
	sort_set(stack.a_stack);
}

int	is_sort(t_stack *stack)
{
	t_list	*temp;
	int		i;

	temp = stack->head;
	i = 0;
	while (i < stack->size - 1)
	{
		if (temp->n < temp->right->n)
			temp = temp->right;
		else
			return (0);
		i++;
	}
	lst_clear(stack);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack_lst	stack;
	t_stack		*a_stack;
	t_stack		*b_stack;

	if (ac <= 1)
		return (0);
	a_stack = create_stack();
	b_stack = create_stack();
	stack.a_stack = a_stack;
	stack.b_stack = b_stack;
	make_stack(ac, av, a_stack);
	indexing(a_stack);
	if (is_sort(stack.a_stack) == 1 || exception_case(stack) == 1)
		return (0);
	push_swap(stack);
	return (0);
}
