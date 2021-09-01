/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:55:25 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/02 00:01:37 by hkawakit         ###   ########.fr       */
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

void	dlstadd_front(t_dlst **lst, t_dlst *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	new->prev = (*lst)->prev;
	(*lst)->prev->next = new;
	(*lst)->prev = new;
	*lst = new;
}
