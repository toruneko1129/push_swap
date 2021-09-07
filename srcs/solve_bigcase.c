/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bigcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:29:44 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/07 00:29:15 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list	*solve_a_util(t_dlst **a, t_dlst **b, int left, int right)
{
	t_list		*ans;
	int			cnt;
	const int	lp = (right - left) / 3 + left;
	const int	rp = (right - left) * 2 / 3 + left;
	int			res;

	ans = NULL;
	cnt = 0;
	/*
	ft_putnbr_fd(lp, STDOUT);
	ft_putendl_fd("", STDOUT);
	ft_putnbr_fd(rp, STDOUT);
	ft_putendl_fd("", STDOUT);
	*/
	while (cnt < rp - left)
	{
		res = (*a)->val;
		if (res < rp)
		{
			exec_add_cmd(PB, a, b, &ans);
			if (res < lp)
				exec_add_cmd(RB, a, b, &ans);
			++cnt;
		}
		else
			exec_add_cmd(RA, a, b, &ans);
		/*
		if (left == 11 && right == 22)
		{
			dbg_stack(*a, *b);
			ft_putendl_fd("", STDOUT);
			ft_putnbr_fd(cnt, STDOUT);
			ft_putendl_fd("", STDOUT);
		}
		*/
	}
	return (ans);
}

t_list	*solve_a(t_dlst **a, t_dlst **b, int left, int right)
{
	t_list		*ans;
	const int	lp = (right - left) / 3 + left;
	const int	rp = (right - left) * 2 / 3 + left;

	if (right - left <= 5)
		return (solve_smallsize(a, b, FALSE, right - left));
	ans = solve_a_util(a, b, left, right);
	while (rp <= dlstlast(*a)->val)
		exec_add_cmd(RRA, a, b, &ans);
	while ((*b)->val >= lp)
		exec_add_cmd(PA, a, b, &ans);
	ft_lstadd_back(&ans, solve_b(a, b, left, lp));
	ft_lstadd_back(&ans, solve_a(a, b, lp, rp));
	ft_lstadd_back(&ans, solve_a(a, b, rp, right));
	return (ans);
}

static t_list	*solve_b_util(t_dlst **a, t_dlst **b, int left, int right)
{
	t_list		*ans;
	int			cnt;
	const int	lp = (right - left) / 3 + left;
	const int	rp = (right - left) * 2 / 3 + left;
	int			res;

	ans = NULL;
	cnt = 0;
	while (cnt < right - lp)
	{
		res = (*b)->val;
		if (res >= lp)
		{
			exec_add_cmd(PA, a, b, &ans);
			if (res < rp)
				exec_add_cmd(RA, a, b, &ans);
			++cnt;
		}
		else
			exec_add_cmd(RB, a, b, &ans);
	}
	while (lp <= dlstlast(*a)->val && dlstlast(*a)->val < rp)
		exec_add_cmd(RRA, a, b, &ans);
	return (ans);
}

t_list	*solve_b(t_dlst **a, t_dlst **b, int left, int right)
{
	t_list		*ans;
	const int	lp = (right - left) / 3 + left;
	const int	rp = (right - left) * 2 / 3 + left;

	if (right - left <= 5)
		return (solve_smallsize(a, b, TRUE, right - left));
	ans = solve_b_util(a, b, left, right);
	ft_lstadd_back(&ans, solve_b(a, b, left, lp));
	ft_lstadd_back(&ans, solve_a(a, b, lp, rp));
	ft_lstadd_back(&ans, solve_a(a, b, rp, right));
	return (ans);
}
