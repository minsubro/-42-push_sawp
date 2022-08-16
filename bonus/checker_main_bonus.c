/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 00:16:30 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/16 11:44:40 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	create_stack_lst(t_stack_lst *stack)
{
	stack->a_stack = create_stack();
	stack->b_stack = create_stack();
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
	return (1);
}

int	main(int ac, char **av)
{
	t_stack_lst	stack;

	if (ac == 1)
		return (0);
	create_stack_lst(&stack);
	make_stack(ac, av, stack.a_stack);
	input_command();
	check_start(stack);
	if (is_sort(stack.a_stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	lst_clear(stack.a_stack);
	lst_clear(stack.b_stack);
	return (0);
}
