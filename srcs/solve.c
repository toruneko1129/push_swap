/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:56:26 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/05 21:44:41 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/debug.h"

static void	solve_smallcase(t_dlst **a, t_dlst **b)
{
	const int	size = dlstsize(*a);

	if (size == 2)
		solve_size2_small(a);
	else if (size == 3)
		solve_size3_small(a);
	else if (size == 4)
		solve_size4_small(a, b);
	else
		solve_size5_small(a, b);
}

void	exec_add_cmd(int type, t_dlst **a, t_dlst **b, t_list **ans)
{
	t_list	*new;

	new = ft_lstnew(cmd_type_tostr(type));
	if (new == NULL)
	{
		ft_lstclear(ans, NULL);
		print_error_exit(a, b);
	}
	ft_lstadd_back(ans, new);
	exec_command(type, a, b);
}

static void	solve_bigcase(t_dlst **a, t_dlst **b)
{
	t_list		*ans;
	int			cnt;
	const int	size = dlstsize(*a);
	int			res;

	ans = NULL;
	cnt = 0;
	while (cnt < size * 2 / 3)
	{
		res = (*a)->val;
		if (res < size * 2 / 3)
		{
			exec_add_cmd(PB, a, b, &ans);
			if (res < size / 3)
				exec_add_cmd(RB, a, b, &ans);
			++cnt;
		}
		else
			exec_add_cmd(RA, a, b, &ans);
	}
	while ((*b)->val >= size / 3)
		exec_add_cmd(PA, a, b, &ans);
	dbg_stack(*a, *b);
	dbg_anslen(ans);
}

void	solve(t_dlst **a, t_dlst **b)
{
	const int	size = dlstsize(*a);

	if (check_issorted(*a, *b))
		return ;
	else if (size <= 5)
		solve_smallcase(a, b);
	else
		solve_bigcase(a, b);
}
