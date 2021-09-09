/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bigcase_utils3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 00:56:08 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/09 12:12:54 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list	*solve_size_o3_util(t_dlst **a, t_dlst **b, int size, int min)
{
	t_list		*ans;

	ans = NULL;
	while (--size)
	{
		if (dlstlast(*a)->val == min + size - 1)
			exec_add_cmd(RRA, a, b, &ans);
		else if ((*b)->val == min + size - 1)
		{
			exec_add_cmd(PA, a, b, &ans);
			if ((*a)->val > (*a)->next->val)
				exec_add_cmd(SA, a, b, &ans);
		}
	}
	return (ans);
}

static t_list	*solve_size_o3_util2(t_dlst **a, t_dlst **b, int size)
{
	t_list		*ans;

	ans = NULL;
	exec_add_cmd(RB, a, b, &ans);
	if (size)
		;
	return (NULL);
}

t_list	*solve_size_over3(t_dlst **a, t_dlst **b, int is_b, int size)
{
	t_list		*ans;
	const int	min = get_minval(a, b, is_b, size);
	int			cnt;

	if (is_b)
		return (solve_size_o3_util2(a, b, size));
	ans = NULL;
	cnt = -1;
	while (++cnt < 2)
	{
		if ((*a)->val > (*a)->next->val)
			exec_add_cmd(SA, a, b, &ans);
		exec_add_cmd(PB, a, b, &ans);
	}
	if (size == 5 && (*a)->val == min + size - 1)
		exec_add_cmd(SA, a, b, &ans);
	if (size == 5)
		exec_add_cmd(RA, a, b, &ans);
	exec_add_cmd(SA + ((*b)->val < (*b)->next->val) * 2, a, b, &ans);
	ft_lstadd_back(&ans, solve_size_o3_util(a, b, size, min));
	return (ans);
}
