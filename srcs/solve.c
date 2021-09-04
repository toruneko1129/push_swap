/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:56:26 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/04 16:39:39 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve(t_dlst **stack_a, t_dlst **stack_b, t_dlst **cmds)
{
	t_dlst	*tmp;

	if (check_issorted(*stack_a, *stack_b))
		return ;
	if (dlstsize(*stack_a) == 2)
	{
		tmp = solve_size2(*stack_a, FALSE);
		if (tmp == NULL)
		{
			free_all(stack_a, stack_b, cmds);
			print_error_exit();
		}
		exec_sort(stack_a, stack_b, tmp);
	}
	//debug
	ft_putendl_fd("NOT sorted", STDOUT);
}
