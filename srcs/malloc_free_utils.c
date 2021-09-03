/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:10:13 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/03 16:20:52 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(t_dlst **a, t_dlst **b, t_dlst **cmds)
{
	if (a != NULL)
		dlstclear(a);
	if (b != NULL)
		dlstclear(b);
	if (cmds != NULL)
		dlstclear(cmds);
}

void	check_init_failed_stack(t_dlst **stack_a, t_dlst **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL)
	{
		free_all(stack_a, stack_b, NULL);
		print_error_exit();
	}
}

void	check_init_failed_cmds(t_dlst **a, t_dlst **b, t_dlst **cmds)
{
	if (*cmds == NULL)
	{
		free_all(a, b, cmds);
		print_error_exit();
	}
}
