/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:56:26 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/05 15:36:53 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	solve_smallcase(t_dlst **a, t_dlst **b)
{
	const int	size = dlstsize(*a);

	if (size == 2)
		solve_size2_small(a);
	else if (size == 3)
		solve_size3_small(a);
	else if (size == 4)
		solve_size4_small(a, b);
}

void	solve(t_dlst **a, t_dlst **b)
{
	const int	size = dlstsize(*a);

	if (check_issorted(*a, *b))
		return ;
	else if (size <= 4)
		solve_smallcase(a, b);
	//debug
	//ft_putendl_fd("NOT sorted", STDOUT);
}
