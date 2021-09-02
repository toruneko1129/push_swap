/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:10:13 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/02 22:49:27 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(t_dlst **a, t_dlst **b, t_list **cmds)
{
	dlstclear(a);
	dlstclear(b);
	ft_lstclear(cmds, NULL);
}

void	check_init_failed(t_dlst **stack_a, t_dlst **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL)
	{
		free_all(stack_a, stack_b, NULL);
		print_error_exit();
	}
}
