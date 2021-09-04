/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:12:42 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/04 17:18:57 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	read_from_stdin(t_dlst **stack_a, t_dlst **stack_b)
{
	char	*cmd;
	int		type;

	cmd = get_next_line(STDIN);
	while (cmd != NULL)
	{
		type = cmd_str_totype(cmd);
		if (type == NIL)
		{
			free(cmd);
			free_all(stack_a, stack_b, NULL);
			print_error_exit();
		}
		exec_command(type, stack_a, stack_b);
		free(cmd);
		cmd = get_next_line(STDIN);
	}
}

int	main(int argc, char **argv)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;

	check_argv(argc, argv);
	stack_a = dlstnew(NIL);
	stack_b = dlstnew(NIL);
	check_init_failed_stack(&stack_a, &stack_b);
	load_stack(argc, argv, &stack_a, &stack_b);
	read_from_stdin(&stack_a, &stack_b);
	print_checker_result(stack_a, stack_b);
	free_all(&stack_a, &stack_b, NULL);
	return (0);
}
