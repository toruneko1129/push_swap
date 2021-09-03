/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:59:40 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/03 21:35:59 by hkawakit         ###   ########.fr       */
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
	dbg_dlst(stack_a, "a");
	exec_command(SA, &stack_a, &stack_b);
	dbg_dlst(stack_a, "a");
	free_all(&stack_a, &stack_b, &cmds);
	return (0);
}
