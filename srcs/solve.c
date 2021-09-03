/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:56:26 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/03 16:07:11 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve(t_dlst **stack_a, t_dlst **stack_b, t_dlst **cmds)
{
	if (check_issorted(*stack_a, *stack_b))
		return ;
	if (cmds)
		;
	ft_putendl_fd("NOT sorted", STDOUT);
}
