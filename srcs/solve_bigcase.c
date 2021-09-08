/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bigcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:43:34 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/08 02:07:02 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_need_sa(t_dlst *a, int l, int r)
{
	if (r - l > 5)
		return (FALSE);
	return (l <= a->next->val && a->next->val < r && a->val > a->next->val);
}

static t_list	*solve_a_util(t_dlst **a, t_dlst **b, int l, int r)
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
			if ((*b)->val < lp)
				exec_add_cmd(RB, a, b, &ans);
			else if (rp - lp <= 5 && (*b)->val < (*b)->next->val)
				exec_add_cmd(SB, a, b, &ans);
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

	if (r - l <= 5)
		return (solve_smallsize(a, b, FALSE, r - l));
	ans = solve_a_util(a, b, l, r);
	while (rp <= dlstlast(*a)->val)
	{
		exec_add_cmd(RRA, a, b, &ans);
		if (check_need_sa(*a, rp, r))
			exec_add_cmd(SA, a, b, &ans);
	}
	while ((*b)->val >= lp)
	{
		exec_add_cmd(PA, a, b, &ans);
		if (check_need_sa(*a, lp, r))
			exec_add_cmd(SA, a, b, &ans);
	}
	ft_lstadd_back(&ans, solve_b(a, b, l, lp));
	ft_lstadd_back(&ans, solve_a(a, b, lp, rp));
	ft_lstadd_back(&ans, solve_a(a, b, rp, r));
	return (ans);
}

static t_list	*solve_b_util(t_dlst **a, t_dlst **b, int l, int r)
{
	t_list		*ans;
	const int	rp = (r - l) * 2 / 3 + l;
	int			cnt;

	ans = NULL;
	cnt = 0;
	while (cnt < r - rp)
	{
		if ((*b)->val >= rp)
		{
			cnt += exec_add_cmd(PA, a, b, &ans);
			if (check_need_sa(*a, rp, r)) 
				exec_add_cmd(SA, a, b, &ans);
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

	if (r - l <= 5)
		return (solve_smallsize(a, b, TRUE, r - l));
	ans = solve_b_util(a, b, l, r);
	cnt = 0;
	while (cnt < rp - lp)
	{
		if ((*b)->val >= lp)
		{
			cnt += exec_add_cmd(PA, a, b, &ans);
			if (check_need_sa(*a, rp, r)) 
				exec_add_cmd(SA, a, b, &ans);
		}
		else
			exec_add_cmd(RB, a, b, &ans);
	}
	ft_lstadd_back(&ans, solve_b(a, b, l, lp));
	ft_lstadd_back(&ans, solve_a(a, b, lp, rp));
	ft_lstadd_back(&ans, solve_a(a, b, rp, r));
	return (ans);
}
