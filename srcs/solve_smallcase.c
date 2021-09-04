/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_smallcase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:37:31 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/04 23:05:30 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*solve_size2(t_dlst **a, t_dlst **b, int is_b)
{
	t_dlst	*stack;
	t_list	*ans;
	int		size;

	stack = *a;
	if (is_b)
		stack = *b;
	ans = NULL;
	size = 0;
	if (stack->val > stack->next->val)
	{
		ft_lstadd_back(&ans, ft_lstnew(cmd_type_tostr(SA + is_b)));
		++size;
	}
	if (ft_lstsize(ans) != size)
		print_error_exit(a, b);
	return (ans);
}

static t_list	*size3_small2(t_dlst **a, t_dlst **b, t_list **ans, int size)
{
	if (*ans == NULL)
	{
		ft_lstadd_back(ans, ft_lstnew("sa\n"));
		ft_lstadd_back(ans, ft_lstnew("rra\n"));
		++size;
	}
	if (ft_lstsize(*ans) != size)
	{
		ft_lstclear(ans, NULL);
		print_error_exit(a, b);
	}
	return (*ans);
}

t_list	*solve_size3_small(t_dlst **a, t_dlst **b)
{
	const int	fst = (*a)->val;
	const int	snd = (*a)->next->val;
	const int	trd = (*a)->next->next->val;
	t_list		*ans;
	int			size;

	ans = NULL;
	size = 1;
	if (fst < trd && trd < snd)
	{
		ft_lstadd_back(&ans, ft_lstnew("rra\n"));
		ft_lstadd_back(&ans, ft_lstnew("sa\n"));
		++size;
	}
	else if (snd < fst && fst < trd)
		ft_lstadd_back(&ans, ft_lstnew("sa\n"));
	else if (trd < fst && fst < snd)
		ft_lstadd_back(&ans, ft_lstnew("rra\n"));
	else if (snd < trd && trd < fst)
		ft_lstadd_back(&ans, ft_lstnew("ra\n"));
	return (size3_small2(a, b, &ans, size));
}
