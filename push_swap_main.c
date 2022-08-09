/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:08:23 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/09 18:39:46 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

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

void move(t_stack_lst stack, int idx)
{
	int	len;

	len = stack.a_stack->size - 1;
	while (a->)
}

int	two_case(t_stack *stack)
{
	if (stack->head->n > stack->head->right->n)
		s(stack, 'a');
	return (1);
}

int	three_case(t_stack *stack)
{
	int a;
	int b;
	int c;
	
	a = stack->head->n;
	b = stack->head->right->n;
	c = stack->head->right->right->n;
	if (a > b && b > c)
	{
		s(stack, 'a');
		rrab(stack, 'a');
	}
	else if (a > b && b < c && a > c)
		r(stack, 'a');
	else if (a < b && b > c && a > c)
		rrab(stack, 'a');	
	else if (a > b && b < c && a < c)
		s(stack, 'a');
	else if (a < c && b > c && a < c)
	{
		s(stack, 'a');
		r(stack, 'a');
	}	
	return (1);
}

int	four_case(t_stack_lst stack)
{
	t_list	*temp;

	while (stack.a_stack->head->n != 0)
	{
		r(stack.a_stack, 'a');
		printf("%d\n", stack.a_stack->head->n);
	}
	p(stack.b_stack, stack.a_stack, 'b');
	three_case(stack.a_stack);
	p(stack.a_stack, stack.b_stack, 'a');
	temp = stack.a_stack->head;
	return (1);
}

int	exception_case(t_stack_lst stack)
{
	if (stack.a_stack->size == 2)
		return (two_case(stack.a_stack));
	if (stack.a_stack->size == 3)
		return (three_case(stack.a_stack));
	if (stack.a_stack->size == 4)
		return (four_case(stack));
	return (0);
}

void	push_swap(t_stack_lst stack)
{
	(void)stack;
	return ;
	
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
	printf("already sort\n");
	return (1);
}

int main(int ac, char **av)
{
	t_stack_lst	stack;
	t_stack		*a_stack;
	t_stack		*b_stack;

	if (ac <= 2)
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