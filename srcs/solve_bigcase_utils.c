/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bigcase_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:51:52 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/09 14:58:43 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_minval(t_dlst **a, t_dlst **b, int is_b, int size)
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

int	get_maxval(t_dlst **a, t_dlst **b, int is_b, int size)
{
	int		max;
	t_dlst	*tmp;
	int		cnt;

	tmp = *a;
	if (is_b)
		tmp = *b;
	max = tmp->val;
	cnt = -1;
	while (++cnt < size - 1)
	{
		tmp = tmp->next;
		if (tmp->val > max)
			max = tmp->val;
	}
	return (max);
}

static int	is_max(t_dlst **a, t_dlst **b, int is_b, int size)
{
	const int	max = get_maxval(a, b, is_b, size);
	t_dlst		*tmp;
	int			cnt;

	tmp = *a;
	cnt = -1;
	while (++cnt < size - 1)
		tmp = tmp->next;
	if (is_b)
		tmp = *b;
	return (tmp->val == max);
}

t_list	*solve_smallsize(t_dlst **a, t_dlst **b, int is_b, int size)
{
	t_list	*ans;

	ans = NULL;
	if (size == 1)
		return (solve_size1(a, b, is_b));
	if (size == 2)
		return (solve_size2(a, b, is_b));
	if (is_max(a, b, is_b, size))
	{
		if (is_b)
			exec_add_cmd(PA, a, b, &ans);
		ft_lstadd_back(&ans, solve_smallsize(a, b, is_b, size - 1));
	}
	else if (size == 3)
		ans = solve_size3(a, b, is_b);
	else
		ans = solve_size_over3(a, b, FALSE, size);
	return (ans);
}
