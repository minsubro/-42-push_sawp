/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 00:16:30 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/14 02:43:47 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	create_stack_lst(t_stack_lst *stack)
{
	stack->a_stack = create_stack();
	stack->b_stack = create_stack();
}

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



void command_exe(char *command, t_stack_lst stack)
{
	
}

#include <stdio.h>
void check_start(t_stack_lst stack)
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

int	main(int ac, char **av)
{
	t_stack_lst	stack;

	if (ac == 1)
		return (0);
	create_stack_lst(&stack);
	make_stack(ac, av, stack.a_stack);
	input_command();
	check_start(stack);
	
}