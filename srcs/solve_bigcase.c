/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bigcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:43:34 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/09 12:17:34 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*solve_a_util(t_dlst **a, t_dlst **b, int l, int r)
{
	t_list		*ans;
	const int	lp = (r - l) / 3 + l;
	const int	rp = (r - l) * 2 / 3 + l;
	int			cnt;

	ans = NULL;
	cnt = 0;
	while (cnt < rp - l)
	{
		if ((*a)->val < rp)
		{
			cnt += exec_add_cmd(PB, a, b, &ans);
			if ((*b)->val >= lp)
				exec_add_cmd(RB + (rp <= (*a)->val && (*a)->val < r),
					a, b, &ans);
		}
		else
			exec_add_cmd(RA, a, b, &ans);
	}
	return (ans);
}

t_list	*solve_a(t_dlst **a, t_dlst **b, int l, int r)
{
	t_list		*ans;
	const int	lp = (r - l) / 3 + l;
	const int	rp = (r - l) * 2 / 3 + l;
	int			cnt;

	if (r - l <= 3)
		return (solve_smallsize(a, b, FALSE, r - l));
	ans = solve_a_util(a, b, l, r);
	cnt = -1;
	while (rp <= dlstlast(*a)->val && dlstlast(*a)->val < r && ++cnt < rp - lp)
		exec_add_cmd(RRR, a, b, &ans);
	if (rp <= dlstlast(*a)->val && dlstlast(*a)->val < r)
		exec_add_cmd(RRA, a, b, &ans);
	while (++cnt < rp - lp)
		exec_add_cmd(RRB, a, b, &ans);
	ft_lstadd_back(&ans, solve_a(a, b, rp, r));
	ft_lstadd_back(&ans, solve_b(a, b, lp, rp));
	ft_lstadd_back(&ans, solve_b(a, b, l, lp));
	return (ans);
}

static t_list	*solve_b_util(t_dlst **a, t_dlst **b, int l, int r)
{
	t_list		*ans;
	const int	lp = (r - l) / 3 + l;
	const int	rp = (r - l) * 2 / 3 + l;
	int			cnt;

	ans = NULL;
	cnt = 0;
	while (cnt < r - lp)
	{
		if ((*b)->val >= lp)
		{
			cnt += exec_add_cmd(PA, a, b, &ans);
			if (lp <= (*a)->val && (*a)->val < rp)
				exec_add_cmd(RA + (l <= (*b)->val && (*b)->val < lp) * 2,
					a, b, &ans);
		}
		else
			exec_add_cmd(RB, a, b, &ans);
	}
	return (ans);
}

t_list	*solve_b(t_dlst **a, t_dlst **b, int l, int r)
{
	t_list		*ans;
	const int	lp = (r - l) / 3 + l;
	const int	rp = (r - l) * 2 / 3 + l;
	int			cnt;

	if (r - l <= 3)
		return (solve_smallsize(a, b, TRUE, r - l));
	ans = solve_b_util(a, b, l, r);
	cnt = -1;
	ft_lstadd_back(&ans, solve_a(a, b, rp, r));
	while (l <= dlstlast(*b)->val && dlstlast(*b)->val < lp && ++cnt < rp - lp)
		exec_add_cmd(RRR, a, b, &ans);
	while (++cnt < rp - lp)
		exec_add_cmd(RRA, a, b, &ans);
	ft_lstadd_back(&ans, solve_a(a, b, lp, rp));
	ft_lstadd_back(&ans, solve_b(a, b, l, lp));
	return (ans);
}
