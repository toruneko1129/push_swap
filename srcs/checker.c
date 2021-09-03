/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:12:42 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/04 01:30:43 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	read_from_stdin(t_dlst **cmds)
{
	char	*cmd;
	int		type;
	t_dlst	*new;

	cmd = get_next_line(STDIN);
	while (cmd != NULL)
	{
		type = cmd_str_totype(cmd);
		if (type == NIL)
		{
			free(cmd);
			return (FAILED);
		}
		new = dlstnew(type);
		if (new == NULL)
		{
			free(cmd);
			return (FAILED);
		}
		dlstadd_back(cmds, new);
		free(cmd);
		cmd = get_next_line(STDIN);
	}
	return (SUCCESS);
}

static void	exec_sort(t_dlst **stack_a, t_dlst **stack_b, t_dlst *cmds)
{
	while (cmds->val != NIL)
	{
		exec_command(cmds->val, stack_a, stack_b);
		cmds = cmds->next;
	}
}

int	main(int argc, char **argv)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	t_dlst	*cmds;

	check_argv(argc, argv);
	stack_a = dlstnew(NIL);
	stack_b = dlstnew(NIL);
	check_init_failed_stack(&stack_a, &stack_b);
	load_stack(argc, argv, &stack_a, &stack_b);
	cmds = dlstnew(NIL);
	check_init_failed_cmds(&stack_a, &stack_b, &cmds);
	if (read_from_stdin(&cmds))
	{
		free_all(&stack_a, &stack_b, &cmds);
		print_error_exit();
	}
	exec_sort(&stack_a, &stack_b, cmds);
	print_checker_result(stack_a, stack_b);
	free_all(&stack_a, &stack_b, &cmds);
	return (0);
}
