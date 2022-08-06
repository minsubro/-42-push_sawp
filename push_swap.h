/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:33:03 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/06 15:12:48 by minsukan         ###   ########.fr       */
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
	int				idx;
	struct s_list	*next;
}					t_list;

typedef struct s_sort
{
	int left;
	int right;
	int lp;
	int rp;
	int l_area;
	int now;
	int r_area;
}			t_sort;



#endif