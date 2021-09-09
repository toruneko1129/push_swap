/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bigcase_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 22:11:04 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/09 14:26:03 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*solve_size1(t_dlst **a, t_dlst **b, int is_b)
{
	t_list	*ans;

	ans = NULL;
	if (is_b)
		exec_add_cmd(PA, a, b, &ans);
	return (ans);
}

t_list	*solve_size2(t_dlst **a, t_dlst **b, int is_b)
{
	t_list	*ans;

	ans = NULL;
	if (!is_b && (*a)->val > (*a)->next->val)
		exec_add_cmd(SA, a, b, &ans);
	else if (is_b && (*b)->val < (*b)->next->val)
		exec_add_cmd(SB, a, b, &ans);
	if (is_b)
	{
		exec_add_cmd(PA, a, b, &ans);
		exec_add_cmd(PA, a, b, &ans);
	}
	return (ans);
}

int	solve_size3_util(t_dlst **a, t_dlst **b, int is_b, int pos)
{
	t_dlst	*tmp;

	tmp = *a;
	if (is_b)
		tmp = *b;
	while (pos--)
		tmp = tmp->next;
	return (tmp->val);
}

t_list	*solve_size3(t_dlst **a, t_dlst **b, int is_b)
{
	t_list		*ans;
	const int	fst = solve_size3_util(a, b, is_b, 0);
	const int	snd = solve_size3_util(a, b, is_b, 1);
	const int	trd = solve_size3_util(a, b, is_b, 2);

	ans = NULL;
	if (!is_b)
	{
		if (fst > snd && fst > trd)
			exec_add_cmd(SA, a, b, &ans);
		exec_add_cmd(RA, a, b, &ans);
		exec_add_cmd(SA, a, b, &ans);
		exec_add_cmd(RRA, a, b, &ans);
	}
	else
	{
		if (trd > fst && trd > snd)
			exec_add_cmd(RB, a, b, &ans);
		exec_add_cmd(SB, a, b, &ans);
		exec_add_cmd(PA, a, b, &ans);
		if (trd > fst && trd > snd)
			exec_add_cmd(RRB, a, b, &ans);
	}
	ft_lstadd_back(&ans, solve_size2(a, b, is_b));
	return (ans);
}
