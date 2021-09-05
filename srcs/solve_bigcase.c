/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bigcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:29:44 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/05 21:59:00 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*solve_b(t_dlst **a, t_dlst **b, int left, int right)
{
	t_list		*ans;
	const int	lp = (right - left) / 3 + left;
	const int	rp = (right - left) * 2 / 3 + left;

	ans = NULL;
	return (ans);
}
