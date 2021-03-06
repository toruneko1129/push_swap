/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:59:40 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/09 14:47:45 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;

	check_argv(argc, argv);
	stack_a = dlstnew(NIL);
	stack_b = dlstnew(NIL);
	check_init_failed_stack(&stack_a, &stack_b);
	load_stack(argc, argv, &stack_a, &stack_b);
	solve(&stack_a, &stack_b);
	free_all(&stack_a, &stack_b);
	return (0);
}
