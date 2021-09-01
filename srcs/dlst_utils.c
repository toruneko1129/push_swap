/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:55:25 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/02 01:26:08 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlst	*dlstnew(int val)
{
	t_dlst	*res;

	res = (t_dlst *)malloc(sizeof(t_dlst));
	if (res == NULL)
		return (NULL);
	res->val = val;
	res->prev = res;
	res->next = res;
	return (res);
}

void	dlstadd_front(t_dlst **dlst, t_dlst *new)
{
	if (dlst == NULL || *dlst == NULL || new == NULL)
		return ;
	new->next = *dlst;
	new->prev = (*dlst)->prev;
	(*dlst)->prev->next = new;
	(*dlst)->prev = new;
	*dlst = new;
}

int	dlstsize(t_dlst *dlst)
{
	int		size;

	if (dlst == NULL)
		return (NIL);
	size = 0;
	while (dlst->val != NIL)
	{
		++size;
		dlst = dlst->next;
	}
	return (size);
}

t_dlst	*dlstlast(t_dlst *dlst)
{
	if (dlst == NULL)
		return (NULL);
	return (dlst->prev->prev);
}

void	dlstadd_back(t_dlst **dlst, t_dlst *new)
{
	t_dlst	*last;

	if (dlst == NULL || *dlst == NULL || new == NULL)
		return ;
	last = dlstlast(*dlst);
	new->next = last->next;
	new->prev = last;
	last->next->prev = new;
	last->next = new;
	if ((*dlst)->val == NIL)
		*dlst = (*dlst)->next;
}
