/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bigcase_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 22:42:29 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/06 23:29:23 by hkawakit         ###   ########.fr       */
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

static int	get_minval(t_dlst **a, t_dlst **b, int is_b, int size)
{
	int		min;
	t_dlst	*tmp;
	int		cnt;

	tmp = *a;
	if (is_b)
		tmp = *b;
	min = tmp->val;
	cnt = -1;
	while (++cnt < size - 1)
	{
		tmp = tmp->next;
		if (tmp->val < min)
			min = tmp->val;
	}
	return (min);
}

static t_list	*solve_size4_5_util(t_dlst **a, t_dlst **b, int size)
{
	t_list		*ans;
	const int	min = get_minval(a, b, FALSE, size);
	int			cnt;

	ans = NULL;
	cnt = 0;
	while (cnt < size - 2)
	{
		if ((*a)->val >= min + 2)
		{
			exec_add_cmd(PB, a, b, &ans);
			++cnt;
		}
		else
			exec_add_cmd(RA, a, b, &ans);
	}
	while (min <= dlstlast(*a)->val && dlstlast(*a)->val < min + 2)
		exec_add_cmd(RRA, a, b, &ans);
	ft_lstadd_back(&ans, solve_smallsize(a, b, FALSE, 2));
	ft_lstadd_back(&ans, solve_smallsize(a, b, TRUE, size - 2));
	return (ans);
}

t_list	*solve_size4_5(t_dlst **a, t_dlst **b, int is_b, int size)
{
	t_list		*ans;
	const int	min = get_minval(a, b, is_b, size);
	int			cnt;

	if (!is_b)
		return (solve_size4_5_util(a, b, size));
	ans = NULL;
	cnt = 0;
	while (cnt < 2)
	{
		if ((*b)->val < min + 2)
		{
			exec_add_cmd(PA, a, b, &ans);
			++cnt;
		}
		else
			exec_add_cmd(RB, a, b, &ans);
	}
	ft_lstadd_back(&ans, solve_smallsize(a, b, FALSE, 2));
	ft_lstadd_back(&ans, solve_smallsize(a, b, TRUE, size - 2));
	return (ans);
}
