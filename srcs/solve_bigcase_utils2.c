/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bigcase_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 22:11:04 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/08 01:02:37 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*solve_size2(t_dlst **a, t_dlst **b, int is_b)
{
	t_list	*ans;

	ans = NULL;
	if (!is_b && (*a)->val > (*a)->next->val)
		exec_add_cmd(SA, a, b, &ans);
	if (is_b && (*b)->val > (*b)->next->val)
	{
		exec_add_cmd(PA, a, b, &ans);
		exec_add_cmd(PA, a, b, &ans);
	}
	if (is_b && (*b)->val < (*b)->next->val)
	{
		exec_add_cmd(PA, a, b, &ans);
		exec_add_cmd(RA, a, b, &ans);
		exec_add_cmd(PA, a, b, &ans);
		exec_add_cmd(RA, a, b, &ans);
	}
	else
	{
		exec_add_cmd(RA, a, b, &ans);
		exec_add_cmd(RA, a, b, &ans);
	}
	return (ans);
}


static t_list	*solve_size3_util(t_dlst **a, t_dlst **b)
{
	t_list		*ans;
	const int	fst = (*a)->val;
	const int	snd = (*a)->next->val;
	const int	trd = (*a)->next->next->val;

	ans = NULL;
	if (trd < fst && fst < snd)
	{
		exec_add_cmd(PB, a, b, &ans);
		exec_add_cmd(PB, a, b, &ans);
		exec_add_cmd(RA, a, b, &ans);
		ft_lstadd_back(&ans, solve_size2(a, b, TRUE)); 
	}
	else
	{
		exec_add_cmd(PB, a, b, &ans);
		ft_lstadd_back(&ans, solve_size2(a, b, FALSE)); 
		exec_add_cmd(PA, a, b, &ans);
		exec_add_cmd(RA, a, b, &ans);
	}
	return (ans);
}

t_list	*solve_size3(t_dlst **a, t_dlst **b, int is_b)
{
	t_list		*ans;
	const int	fst = (*b)->val;
	const int	snd = (*b)->next->val;
	const int	trd = (*b)->next->next->val;

	if (!is_b)
		return (solve_size3_util(a, b));
	ans = NULL;
	if (snd < fst && fst < trd)
		exec_add_cmd(SB, a, b, &ans);
	else
		exec_add_cmd(RRB, a, b, &ans);
	exec_add_cmd(PA, a, b, &ans);
	exec_add_cmd(RA, a, b, &ans);
	ft_lstadd_back(&ans, solve_size2(a, b, TRUE));
	return (ans);
}
