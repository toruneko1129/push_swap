/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bigcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:29:44 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/05 22:23:27 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*solve_b(t_dlst **a, t_dlst **b, int left, int right)
{
	t_list		*ans;
	int			cnt;
	const int	lp = (right - left) / 3 + left;
	const int	rp = (right - left) * 2 / 3 + left;
	int			res;

	ans = NULL;
	cnt = right - left;
	while (cnt > lp - left)
	{
		res = (*b)->val;
		if (res >= lp)
		{
			exec_add_cmd(PA, a, b, &ans);
			if (res < rp)
				exec_add_cmd(RA, a, b, &ans);
			--cnt;
		}
		else
			exec_add_cmd(RB, a, b, &ans);
	}
	while (lp <= dlstlast(*a)->val && dlstlast(*a)->val < rp)
		exec_add_cmd(RRA, a, b, &ans);
	return (ans);
}
