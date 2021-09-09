/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:56:26 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/09 14:30:17 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	exec_add_cmd(int type, t_dlst **a, t_dlst **b, t_list **ans)
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
	return (TRUE);
}

static void	solve_bigcase(t_dlst **a, t_dlst **b)
{
	t_list		*ans;
	int			cnt;
	const int	size = dlstsize(*a);

	ans = NULL;
	cnt = 0;
	while (cnt < size * 2 / 3)
	{
		if ((*a)->val < size * 2 / 3)
		{
			cnt += exec_add_cmd(PB, a, b, &ans);
			if ((*b)->val >= size / 3)
				exec_add_cmd(RB + ((*a)->val >= size * 2 / 3), a, b, &ans);
		}
		else
			exec_add_cmd(RA, a, b, &ans);
	}
	cnt = -1;
	while (++cnt < size * 2 / 3 - size / 3)
		exec_add_cmd(RRB, a, b, &ans);
	ft_lstadd_back(&ans, solve_a(a, b, size * 2 / 3, size));
	ft_lstadd_back(&ans, solve_b(a, b, size / 3, size * 2 / 3));
	ft_lstadd_back(&ans, solve_b(a, b, 0, size / 3));
	print_all_cmd(ans);
	ft_lstclear(&ans, NULL);
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
