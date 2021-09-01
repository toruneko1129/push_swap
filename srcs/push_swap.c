/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:59:40 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/02 01:21:26 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/debug.h"

int	main(int argc, char **argv)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;

	check_argv(argc, argv);
	stack_a = dlstnew(NIL);
	stack_b = dlstnew(NIL);
	check_init_failed(stack_a, stack_b);
	//debug mode
	rep(i, argc - 1)
		dlstadd_back(&stack_a, dlstnew(ft_atoi(argv[i + 1])));
	dbg_dlst(stack_a, "a");
	rep(i, 10)
	{
		printf("%p\n", stack_a);
		ft_putnbr_fd(stack_a->val, STDOUT);
		ft_putchar_fd('\n', 1);
		stack_a = stack_a->prev;
	}
	return (0);
}
