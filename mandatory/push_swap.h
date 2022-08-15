/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:33:03 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/15 20:17:29 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				n;
	struct s_list	*left;
	struct s_list	*right;
}					t_list;

typedef struct s_stack
{
	struct s_list	*head;
	struct s_list	*tail;
	int				size;
}					t_stack;

typedef struct s_stack_lst
{
	struct s_stack	*a_stack;
	struct s_stack	*b_stack;
}					t_stack_lst;

typedef struct s_sort
{
	int		left;
	int		right;
	int		lp;
	int		rp;
	int		l_area;
	int		now;
	int		r_area;
}			t_sort;

void	error(void);
void	lst_clear(t_stack *stack);
void	r_area_setting(t_list ***arr, t_sort *var);
void	lst_swap(t_list **a, t_list **b);
t_sort	*create_va_list(int left, int right, t_list ***arr);
void	quick_sort(t_list ***arr, t_sort *var);
void	arr_sort(t_list ***arr, int left, int right);
t_list	*create_new(int n);
int		overlap_check(long long n, t_list *head);
int		ft_atoi(char *str, t_list **stack);
void	make_stack(int ac, char **av, t_stack *stack);
t_list	***make_arr(t_stack *stack);
void	arr_free(t_list ***arr, int size);
void	indexing(t_stack *a_stack);
void	lst_link(t_stack *stack);
int		is_sort(t_stack *stack);
void	s(t_stack *stack, char a);
void	ss(t_stack_lst stack_lst);
void	p(t_stack *dst_stack, t_stack *src_stack, char a);
void	r(t_stack *stack, char a);
void	rr(t_stack_lst stack);
void	rrab(t_stack *stack, char a);
void	rrr(t_stack_lst stack);
char	**ft_split(char const *s, char c, int *acnt);

int		exception_case(t_stack_lst stack);
int		five_case(t_stack_lst stack);
int		four_case(t_stack_lst stack);
int		three_case(t_stack *stack);
int		two_case(t_stack *stack);

void	rotate_all(int *a, int *b, t_stack_lst stack);
void	rotate_a(t_stack *stack, int *a);
void	rotate_b(t_stack *stack, int *a);
void	sort_set(t_stack *stack);

int		find_a_pos(t_stack *stack, int num);
int		ft_compare(int a, int b, int a_pos, int b_pos);
void	get_min_rotate(t_stack_lst stack, int *a, int *b);
void	greed(t_stack_lst stack);

int		mid_idx(t_stack *stack, int num);
int		stack_min(t_stack *stack);
int		min_idx(t_stack *stack, int min);
int		stack_max(t_stack *stack);
int		max_idx(t_stack *stack, int max);

void	a_to_b_all(t_stack_lst stack);
void	find_pivot(int size, int *pivot1, int *pivot2);
void	a_to_b(t_stack_lst stack);

t_stack	*create_stack(void);
int		check(long long num);
void	str_clear(char **str);

#endif