/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:42:44 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/04 01:20:11 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_checker_result(t_dlst *stack_a, t_dlst *stack_b)
{
	if (check_issorted(stack_a, stack_b))
		ft_putendl_fd("OK", STDOUT);
	else
		ft_putendl_fd("KO", STDOUT);
}

void	print_error_exit(void)
{
	ft_putendl_fd("Error", STDERR);
	exit(EXIT_FAILURE);
}
