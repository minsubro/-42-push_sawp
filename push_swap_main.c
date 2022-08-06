/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:08:23 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/06 16:39:49 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	lst_clear(t_list **stack)
{
	t_list	*temp;

	while ((*stack))
	{
		temp = (*stack)->next;
		free((*stack));
		(*stack) = temp;
	}
	error();
}

t_list	*create_new(int n)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->n = n;
	new->next = NULL;
	return (new);
}

int	overlap_check(long long n, t_list *head)
{
	while (head)
	{
		if (n == head->n)
			return (0);
		head = head->next;
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
		if (!((n*sign) <= INT_MAX && (n*sign) >= INT_MIN) || !(str[i] >= '0' && str[i] <= '9'))
			lst_clear(stack);
		i++;
	}
	if (i == 0 || overlap_check(n * sign, *stack) == 0)
		lst_clear(stack);
	return (n * sign);
}

void	make_stack(int ac, char **av, t_list **stack)
{
	int		i;
	t_list	*new;

	i = 1;
	while (i < ac)
	{
		new = create_new(ft_atoi(av[i], stack));
		if (!new)
			lst_clear(stack);
		new->next = *stack;
		*stack = new;
		i++;
	}
}

void test(t_list *start)
{
	while (start)
	{
		printf("%d\n", start->n);
		start = start->next;
	}
}

t_list	**make_arr(t_list *head)
{
	t_list	**arr;
	int		i;

	i = 0;
	arr = (t_list **)malloc(sizeof(t_list *));
	if (!arr)
		return (NULL);
	while (head)
	{
		arr[i] = head;
		head = head->next;
		i++;
	}
	return (arr);		
}

void	lst_swap(t_list **a, t_list **b)
{
	t_list	*temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

void	r_area_setting(t_list **arr, t_sort *var)
{
	while (arr[var->r_area]->n > var->rp && var->now < var->r_area)
		(var->r_area)--;
	lst_swap(&arr[var->now], &arr[var->r_area]);
	(var->r_area)--;
	if (arr[var->now]->n < var->lp)
	{
		lst_swap(&arr[var->now], &arr[var->l_area]);
		(var->l_area)++;
	}
}

void	quick_sort(t_list **arr, t_sort *var)
{
	while (var->now <= var->r_area)
	{
		if (arr[var->now]->n < var->lp)
		{
			lst_swap(&arr[var->l_area], &arr[var->now]);
			(var->l_area)++;
		}
		else
		{
			if (arr[var->now]->n > var->rp)
				r_area_setting(arr, var);	
		}
		(var->now)++;
	}
	(var->l_area)--;
	(var->r_area)--;
	lst_swap(&arr[var->left], &arr[var->l_area]);
	lst_swap(&arr[var->right], &arr[var->r_area]);
}

t_sort	*create_va_list(int left, int right, t_list **arr)
{
	t_sort	*new;

	new = (t_sort *)malloc(sizeof(t_sort));
	if (!new)
		error();
	new->left = left;
	new->right = right;
	new->lp = arr[left]->n;
	new->rp = arr[right]->n;
	new->l_area = left + 1;
	new->now = left + 1;
	new->r_area = right - 1;
	return (new);
}

void	arr_sort(t_list **arr, int left, int right)
{
	t_sort	*var_list;

	if (left <= right)
	{
		if (arr[left]->n > arr[right]->n)
			lst_swap(&arr[left], &arr[right]);
		var_list = create_va_list(left, right, arr);
		quick_sort(arr, var_list);
		arr_sort(arr, left, (var_list->l_area) - 1);
		arr_sort(arr, (var_list->l_area) + 1, (var_list->r_area) - 1);
		arr_sort(arr, (var_list->r_area) + 1, right);
	}
}

void indexing(t_list **a_stack, int cnt)
{
	t_list	**arr;
	int		i;

	i = 0;
	arr = make_arr(*a_stack);
	if (!arr)
		lst_clear(a_stack);
	for(int i = 0; i<cnt; i++)
	{
		printf("%d\n", arr[i]->n);
	}
	arr_sort(arr, 0, cnt - 1);
	while (i < cnt)
	{
		arr[i]->idx = i;
		i++;
	}
	///
	for(int i = 0; i<cnt; i++)
	{
		printf("%d\n", arr[i]->n);
	}
	///
	free (arr);
}

int main(int ac, char **av)
{
	t_list	*a_stack;

	if (ac == 1)
		error();
	make_stack(ac, av, &a_stack);
	indexing(&a_stack, ac - 1);
	//push_swap(&a_stack);
	return (0);	
}