/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_smallcase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:37:31 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/04 16:10:45 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlst	*solve_size2(t_dlst *stack, int is_b)
{
	t_dlst	ans;
	int		size;

	ans = dlstnew(NIL);
	size = 0;
	if (ans == NULL)
		return (NULL);
	if (stack->val > stack->next->val)
	{
		dlstadd_back(&ans, dlstnew(SA + is_b));
		++size;
	}
	if (dlstsize(ans) != size)
	{
		dlstclear(&ans);
		return (NULL);
	}
	return (ans);
}
