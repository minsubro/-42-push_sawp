/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 00:16:45 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/14 02:05:28 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "gnl/get_next_line_bonus.h"

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

char	**ft_split(char const *s, char c, int *acnt);
void input_commannd(t_stack_lst stack);
void	create_stack_lst(t_stack_lst *stack);
void	error(void);
t_stack	*create_stack(void);
int	check(long long num);
void	lst_link(t_stack *stack);
t_list	*create_new(int n);
void	make_stack(int ac, char **av, t_stack *stack);
int	overlap_check(long long n, t_list *head);
int	ft_atoi(char *str, t_list **stack);
void	error(void);


#endif