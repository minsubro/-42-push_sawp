/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:09:22 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/14 00:05:09 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_area_setting(t_list ***arr, t_sort *var)
{
	while ((*(arr[var->r_area]))->n > var->rp && var->now < var->r_area)
		(var->r_area)--;
	lst_swap(arr[var->now], arr[var->r_area]);
	(var->r_area)--;
	if ((*(arr[var->now]))->n < var->lp)
	{
		lst_swap(arr[var->now], arr[var->l_area]);
		(var->l_area)++;
	}
}

void	lst_swap(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_sort	*create_va_list(int left, int right, t_list ***arr)
{
	t_sort	*new;

	new = (t_sort *)malloc(sizeof(t_sort));
	if (!new)
		error();
	new->left = left;
	new->right = right;
	new->lp = (*(arr[left]))->n;
	new->rp = (*(arr[right]))->n;
	new->l_area = left + 1;
	new->now = left + 1;
	new->r_area = right - 1;
	return (new);
}

void	quick_sort(t_list ***arr, t_sort *var)
{
	while (var->now <= var->r_area)
	{
		if ((*(arr[var->now]))->n < var->lp)
		{
			lst_swap(arr[var->l_area], arr[var->now]);
			(var->l_area)++;
		}
		else
		{
			if ((*(arr[var->now]))->n > var->rp)
				r_area_setting(arr, var);
		}
		(var->now)++;
	}
	(var->l_area)--;
	(var->r_area)++;
	lst_swap(arr[var->left], arr[var->l_area]);
	lst_swap(arr[var->right], arr[var->r_area]);
}

void	arr_sort(t_list ***arr, int left, int right)
{
	t_sort	*var_list;

	if (left < right)
	{
		if ((*(arr[left]))->n > (*(arr[right]))->n)
			lst_swap(arr[left], arr[right]);
		var_list = create_va_list(left, right, arr);
		quick_sort(arr, var_list);
		arr_sort(arr, left, (var_list->l_area) - 1);
		arr_sort(arr, (var_list->l_area) + 1, (var_list->r_area) - 1);
		arr_sort(arr, (var_list->r_area) + 1, right);
	}
}
