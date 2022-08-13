/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:08:25 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/14 02:08:33 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list_g
{
	char			*str;
	int				fd;
	struct s_list_g	*next;
}					t_list_g;

char		*get_next_line(int fd);
t_list_g	*lstnew(int fd);
t_list_g	*find_list(t_list_g **head, int fd);
void		lstdel(t_list_g **head, int fd);
t_list_g	*lstiter(t_list_g *head, int fd);
int			ft_strlen(char *str);
int			lf_check(char *str);
char		*ft_strjoin(char *s1, char *s2, int idx);
char		*ft_make(char **str);
char		*make_str(t_list_g *lst, int *len);

#endif