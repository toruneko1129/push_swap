/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:59:40 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/02 23:30:09 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	t_list	*cmds;

	check_argv(argc, argv);
	stack_a = dlstnew(NIL);
	stack_b = dlstnew(NIL);
	cmds = NULL;
	check_init_failed(&stack_a, &stack_b);
	load_stack(argc, argv, &stack_a, &stack_b);
	free_all(&stack_a, &stack_b, &cmds);
	return (0);
}
