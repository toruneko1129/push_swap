/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:11:21 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/02 23:33:15 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_val(int argc, char **argv, int num)
{
	int		val;
	int		i;

	val = 0;
	i = 0;
	while (++i < argc)
	{
		if (num > ft_atoi(argv[i]))
			++val;
	}
	return (val);
}

void	load_stack(int argc, char **argv, t_dlst **stack_a, t_dlst **stack_b)
{
	int		val;
	t_dlst	*res;
	int		i;

	i = 0;
	while (++i < argc)
	{
		val = get_val(argc, argv, ft_atoi(argv[i]));
		res = dlstnew(val);
		if (res == NULL)
		{
			free_all(stack_a, stack_b, NULL);
			print_error_exit();
		}
		dlstadd_back(stack_a, res);
	}
}
