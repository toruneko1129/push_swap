/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:48:45 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/03 21:33:02 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	exec_cmd_swap(t_dlst **stack)
{
	int		tmp;

	if ((*stack)->next->val == NIL)
		return ;
	tmp = (*stack)->val;
	(*stack)->val = (*stack)->next->val;
	(*stack)->next->val = tmp;
}

void	exec_command(int type, t_dlst **stack_a, t_dlst **stack_b)
{
	if (type == SA || type == SS)
		exec_cmd_swap(stack_a);
	if (type == SB || type == SS)
		exec_cmd_swap(stack_b);
}
