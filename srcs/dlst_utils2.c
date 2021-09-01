/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 01:26:48 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/02 02:06:56 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	dlstdelone(t_dlst **dlst)
{
	t_dlst	*new_front;

	if ((*dlst)->val == NIL)
		new_front = NULL;
	else
		new_front = (*dlst)->next;
	(*dlst)->prev->next = (*dlst)->next;
	(*dlst)->next->prev = (*dlst)->prev;
	free(*dlst);
	*dlst = new_front;
}

void	dlstclear(t_dlst **dlst)
{
	while (*dlst != NULL)
		dlstdelone(dlst);
}
