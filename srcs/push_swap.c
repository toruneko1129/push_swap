/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:59:40 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/03 22:16:45 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/debug.h"

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
	//solve(&stack_a, &stack_b, &cmds);
	//debug mode
	dbg_stack(stack_a, stack_b);
	exec_command(PA, &stack_a, &stack_b);
	exec_command(RB, &stack_a, &stack_b);
	exec_command(SA, &stack_a, &stack_b);
	dbg_stack(stack_a, stack_b);
	rep(i, 3)
	{
		exec_command(PB, &stack_a, &stack_b);
		if (!i)
			exec_command(RB, &stack_a, &stack_b);
	}
	dbg_stack(stack_a, stack_b);
	exec_command(RA, &stack_a, &stack_b);
	exec_command(RB, &stack_a, &stack_b);
	dbg_stack(stack_a, stack_b);
	rep(i, 2)
	{
		exec_command(RR, &stack_a, &stack_b);
		dbg_stack(stack_a, stack_b);
	}
	//debug end
	free_all(&stack_a, &stack_b, &cmds);
	return (0);
}
