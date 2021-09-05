/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bigcase_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 22:56:53 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/05 22:59:44 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*solve_size2(t_dlst **a, t_dlst **b, int is_b)
{
	t_list	*ans;
	t_dlst	*stack;

	stack = *a;
	if (is_b)
		stack = *b;
}
