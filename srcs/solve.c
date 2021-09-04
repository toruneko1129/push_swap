/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:56:26 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/04 18:50:55 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exec_sort(t_dlst **stack_a, t_dlst **stack_b, t_list *cmds)
{
	int		type;

	print_cmds(cmds);
	while (cmds != NULL)
	{
		type = cmd_str_totype(cmds->content);
		exec_command(type, stack_a, stack_b);
		cmds = cmds->next;
	}
}

void	solve(t_dlst **stack_a, t_dlst **stack_b)
{
	t_list	*ans;

	if (check_issorted(*stack_a, *stack_b))
		return ;
	if (dlstsize(*stack_a) == 2)
	{
		ans = solve_size2(stack_a, stack_b, FALSE);
		exec_sort(stack_a, stack_b, ans);
		ft_lstclear(&ans, NULL);
	}
	//debug
	//ft_putendl_fd("NOT sorted", STDOUT);
}
