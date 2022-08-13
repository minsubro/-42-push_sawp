/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:47:33 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/13 23:59:30 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_link(t_stack *stack)
{
	t_list	*temp;
	int		i;

	if (stack->size == 0)
		return ;
	i = 0;
	temp = stack->head;
	while (i < stack->size - 1)
	{
		temp = temp->right;
		i++;
	}
	stack->tail = temp;
	stack->tail->right = stack->head;
	stack->head->left = stack->tail;
}

t_list	*create_new(int n)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->n = n;
	new->right = NULL;
	new->left = 0;
	return (new);
}

void	make_stack(int ac, char **av, t_stack *stack)
{
	int		i;
	t_list	*new;
	char	**str;
	int		cnt;

	i = ac - 1;
	while (i)
	{
		str = ft_split(av[i], ' ', &cnt);
		while (cnt - 1 >= 0 && str[cnt - 1])
		{
			new = create_new(ft_atoi(str[cnt - 1], &(stack->head)));
			if (!new)
				lst_clear(stack);
			new->right = stack->head;
			if (stack->head)
				stack->head->left = new;
			stack->head = new;
			(stack->size)++;
			cnt--;
		}
		i--;
	}
	lst_link(stack);
}

int	overlap_check(long long n, t_list *head)
{
	while (head)
	{
		if (n == head->n)
			return (0);
		head = head->right;
	}
	return (1);
}

int	ft_atoi(char *str, t_list **stack)
{
	long long	n;
	int			sign;
	int			i;

	n = 0;
	i = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (str[i])
	{
		n = n * 10 + (str[i] - 48);
		if (check(n * sign) || !(str[i] >= '0' && str[i] <= '9'))
			error();
		i++;
	}
	if (i == 0 || overlap_check(n * sign, *stack) == 0)
		error();
	return (n * sign);
}
