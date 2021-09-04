/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:08:30 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/04 18:43:41 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*cmd_type_tostr(int type)
{
	if (type == SA)
		return ("sa\n");
	else if (type == SB)
		return ("sb\n");
	else if (type == SS)
		return ("ss\n");
	else if (type == PA)
		return ("pa\n");
	else if (type == PB)
		return ("pb\n");
	else if (type == RA)
		return ("ra\n");
	else if (type == RB)
		return ("rb\n");
	else if (type == RR)
		return ("rr\n");
	else if (type == RRA)
		return ("rra\n");
	else if (type == RRB)
		return ("rrb\n");
	else if (type == RRR)
		return ("rrr\n");
	return ("\n");
}

int	cmd_str_totype(char *str)
{
	const size_t	len = ft_strlen(str);

	if (!ft_strncmp(str, "sa\n", len))
		return (SA);
	else if (!ft_strncmp(str, "sb\n", len))
		return (SB);
	else if (!ft_strncmp(str, "ss\n", len))
		return (SS);
	else if (!ft_strncmp(str, "pa\n", len))
		return (PA);
	else if (!ft_strncmp(str, "pb\n", len))
		return (PB);
	else if (!ft_strncmp(str, "rra\n", len))
		return (RRA);
	else if (!ft_strncmp(str, "rrb\n", len))
		return (RRB);
	else if (!ft_strncmp(str, "rrr\n", len))
		return (RRR);
	else if (!ft_strncmp(str, "ra\n", len))
		return (RA);
	else if (!ft_strncmp(str, "rb\n", len))
		return (RB);
	else if (!ft_strncmp(str, "rr\n", len))
		return (RR);
	return (NIL);
}
