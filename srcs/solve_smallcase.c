/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_smallcase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:37:31 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/04 19:09:27 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*solve_size2(t_dlst **a, t_dlst **b, int is_b)
{
	t_dlst	*stack;
	t_list	*ans;
	int		size;
	char	*cmd;

	stack = *a;
	if (is_b)
		stack = *b;
	ans = NULL;
	size = 0;
	if (stack->val > stack->next->val)
	{
		cmd = cmd_type_tostr(SA + is_b);
		ft_lstadd_back(&ans, ft_lstnew(cmd));
		++size;
	}
	if (ft_lstsize(ans) != size)
		print_error_exit(a, b);
	return (ans);
}
