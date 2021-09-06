/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bigcase_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 22:56:53 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/06 22:19:15 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*solve_size2(t_dlst **a, t_dlst **b, int is_b)
{
	t_list	*ans;

	ans = NULL;
	if (!is_b && (*a)->val > (*a)->next->val)
		exec_add_cmd(SA, a, b, &ans);
	return (ans);
}

static t_list	*solve_size3_util2(t_dlst **a, t_dlst **b)
{
	t_list		*ans;
	const int	fst = (*a)->val;
	const int	snd = (*a)->next->val;
	const int	trd = (*a)->next->next->val;

	ans = NULL;
	if (fst < snd && snd < trd)
		return (NULL);
	else if (snd < fst && fst < trd)
		exec_add_cmd(SA, a, b, &ans);
	else
	{
		exec_add_cmd(PB, a, b, &ans);
		if (trd < snd && snd < fst)
			exec_add_cmd(SA, a, b, &ans);
		exec_add_cmd(RA, a, b, &ans);
		exec_add_cmd(RA, a, b, &ans);
		exec_add_cmd(PA, a, b, &ans);
		exec_add_cmd(RRA, a, b, &ans);
		exec_add_cmd(RRA, a, b, &ans);
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
	if (fst < trd && trd < snd)
	{
		exec_add_cmd(RA, a, b, &ans);
		exec_add_cmd(SA, a, b, &ans);
		exec_add_cmd(RRA, a, b, &ans);
	}
	else if (trd < fst && fst < snd)
	{
		exec_add_cmd(PB, a, b, &ans);
		exec_add_cmd(PB, a, b, &ans);
		exec_add_cmd(RA, a, b, &ans);
		exec_add_cmd(PA, a, b, &ans);
		exec_add_cmd(PA, a, b, &ans);
		exec_add_cmd(RRA, a, b, &ans);
	}
	else
		return (solve_size3_util2(a, b));
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
	if (fst < trd && trd < snd)
		exec_add_cmd(RB, a, b, &ans);
	else if (snd < fst && fst < trd)
		exec_add_cmd(SB, a, b, &ans);
	else if (trd < fst && fst < snd)
		exec_add_cmd(RRB, a, b, &ans);
	else if (snd < trd && trd < fst)
		exec_add_cmd(RB, a, b, &ans);
	return (ans);
}

static t_list	*solve_smallsize_util(t_dlst **a, t_dlst **b, int size)
{
	t_list	*ans;
	int		cnt;

	ans = NULL;
	cnt = -1;
	if ((*b)->val < (*b)->next->val)
	{
		while (++cnt < size)
		{
			exec_add_cmd(PA, a, b, &ans);
			exec_add_cmd(RA, a, b, &ans);
		}
	}
	else
	{
		while (++cnt < size)
			exec_add_cmd(PA, a, b, &ans);
		cnt = -1;
		while (++cnt < size)
			exec_add_cmd(RA, a, b, &ans);
	}
	return (ans);
}

t_list	*solve_smallsize(t_dlst **a, t_dlst **b, int is_b, int size)
{
	t_list	*ans;
	int		cnt;

	if (size == 2)
		ans = solve_size2(a, b, is_b);
	else if (size == 3)
		ans = solve_size3(a, b, is_b);
	else if (size == 4)
		ans = NULL;
	else
		ans = NULL;
	cnt = -1;
	if (!is_b)
	{
		while (++cnt < size)
			exec_add_cmd(RA, a, b, &ans);
	}
	else
		ft_lstadd_back(&ans, solve_smallsize_util(a, b, size));
	return (ans);
}
