/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bigcase_utils3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 01:46:56 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/08 02:03:59 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*solve_size4(t_dlst **a, t_dlst **b, int is_b)
{
	t_list	*ans;
	int		cnt;
	int		cnt_ara;

	ans = NULL;
	exec_add_cmd(PB - is_b, a, b, &ans);
	exec_add_cmd(PB - is_b, a, b, &ans);
	if ((*a)->val > (*a)->next->val && (*b)->val > (*b)->next->val)
		exec_add_cmd(SS, a, b, &ans);
	else if ((*a)->val > (*a)->next->val)
		exec_add_cmd(SA, a, b, &ans);
	else if ((*b)->val > (*b)->next->val)
		exec_add_cmd(SB, a, b, &ans);
	cnt = -1;
	cnt_ara = 0;
	while (++cnt < 4)
	{
		if (cnt_ara == 2 || ((*b)->val != NIL && (*a)->val > (*b)->val))
			exec_add_cmd(PA, a, b, &ans);
		else
			++cnt_ara;
		exec_add_cmd(RA, a, b, &ans);
	}
	return (ans);
}
