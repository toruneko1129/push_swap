/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:56:26 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/04 23:02:52 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exec_sort(t_dlst **a, t_dlst **b, t_list *cmds)
{
	int		type;

	print_cmds(cmds);
	while (cmds != NULL)
	{
		type = cmd_str_totype(cmds->content);
		exec_command(type, a, b);
		cmds = cmds->next;
	}
}

static void	solve_smallcase(t_dlst **a, t_dlst **b)
{
	const int	size = dlstsize(*a);
	t_list		*ans;

	if (size == 2)
		ans = solve_size2(a, b, FALSE);
	else if (size == 3)
		ans = solve_size3_small(a, b);
	else
		ans = NULL;
	exec_sort(a, b, ans);
	ft_lstclear(&ans, NULL);
}

void	solve(t_dlst **a, t_dlst **b)
{
	const int	size = dlstsize(*a);

	if (check_issorted(*a, *b))
		return ;
	else if (size <= 3)
		solve_smallcase(a, b);
	//debug
	//ft_putendl_fd("NOT sorted", STDOUT);
}
