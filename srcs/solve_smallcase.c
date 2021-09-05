/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_smallcase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:37:31 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/05 15:18:07 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_size2_small(t_dlst **a)
{
	if ((*a)->val > (*a)->next->val)
		print_cmd(SA);
}

void	solve_size3_small(t_dlst **a)
{
	const int	fst = (*a)->val;
	const int	snd = (*a)->next->val;
	const int	trd = (*a)->next->next->val;

	if (fst < trd && trd < snd)
	{
		print_cmd(RRA);
		print_cmd(SA);
	}
	else if (snd < fst && fst < trd)
		print_cmd(SA);
	else if (trd < fst && fst < snd)
		print_cmd(RRA);
	else if (snd < trd && trd < fst)
		print_cmd(RA);
	else if (trd < snd && snd < fst)
	{
		print_cmd(SA);
		print_cmd(RRA);
	}
}

/*
void	solve_size4_small(t_dlst **a, t_dlst **b)
{
	t_list	*ans;
	int		size;
	int		type;

	while (dlstsize(*b) < 2)
	{
		type = RA;
		if ((*a)->val < 2)
			type = PB;
		print_cmd(type);
		exec_command(type, a, b);
	}
	ans = solve_size2(a, b, FALSE);
}
*/
