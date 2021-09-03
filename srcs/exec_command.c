/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:48:45 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/03 21:45:16 by hkawakit         ###   ########.fr       */
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

static void	exec_cmd_push(t_dlst **stack_dst, t_dlst **stack_src)
{
	t_dlst	*top;

	if ((*stack_src)->val == NIL)
		return ;
	top = *stack_src;
	*stack_src = (*stack_src)->next;
	top->prev->next = top->next;
	top->next->prev = top->prev;
	dlstadd_front(stack_dst, top);
}

void	exec_command(int type, t_dlst **stack_a, t_dlst **stack_b)
{
	if (type == SA || type == SS)
		exec_cmd_swap(stack_a);
	if (type == SB || type == SS)
		exec_cmd_swap(stack_b);
	if (type == PA)
		exec_cmd_push(stack_a, stack_b);
	if (type == PB)
		exec_cmd_push(stack_b, stack_a);
}
