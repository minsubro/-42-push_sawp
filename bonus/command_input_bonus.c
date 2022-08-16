/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_input_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:26:13 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/16 17:06:30 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	input_command(void)
{
	char	*text;
	char	buf;
	int		fd;

	text = "command.txt";
	fd = open(text, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		error();
	while (read(0, &buf, 1) > 0)
		write(fd, &buf, 1);
	close(fd);
}

void	check_start(t_stack_lst stack)
{
	char	*str;
	int		fd;

	fd = open("command.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		command_exe(str, stack);
		free(str);
	}
}

void	command_exe(char *command, t_stack_lst stack)
{
	if (ft_strcmp("sa", command))
		s(stack.a_stack);
	if (ft_strcmp("sb", command))
		s(stack.b_stack);
	if (ft_strcmp("ss", command))
		ss(stack);
	if (ft_strcmp("pa", command))
		p(stack.a_stack, stack.b_stack);
	if (ft_strcmp("pb", command))
		p(stack.b_stack, stack.a_stack);
	if (ft_strcmp("ra", command))
		r(stack.a_stack);
	if (ft_strcmp("rb", command))
		r(stack.b_stack);
	if (ft_strcmp("rr", command))
		rr(stack);
	if (ft_strcmp("rra", command))
		rrab(stack.a_stack);
	if (ft_strcmp("rrb", command))
		rrab(stack.b_stack);
	if (ft_strcmp("rrr", command))
		rrr(stack);
	else
		error();
}

int	ft_strcmp(char *s1, char *s2)
{
	while (1)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
		if (*s1 == 0 && (*s2 == 0 || *s2 == '\n'))
			break ;
	}
	return (1);
}
