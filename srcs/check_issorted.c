/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_issorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:08:34 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/04 16:39:39 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_issorted(t_dlst *stack_a, t_dlst *stack_b)
{
	int		res;

	if (stack_b->val != NIL)
		return (FALSE);
	res = -1;
	while (stack_a->val != NIL)
	{
		if (stack_a->val != ++res)
			return (FALSE);
		stack_a = stack_a->next;
	}
	return (TRUE);
}

void	exec_sort(t_dlst **stack_a, t_dlst **stack_b, t_dlst *cmds)
{
	while (cmds->val != NIL)
	{
		exec_command(cmds->val, stack_a, stack_b);
		cmds = cmds->next;
	}
}
