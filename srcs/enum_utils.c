/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:08:30 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/03 18:35:08 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*cmd_type_tostr(int type)
{
	if (type == SA)
		return ("sa");
	else if (type == SB)
		return ("sb");
	else if (type == SS)
		return ("ss");
	else if (type == PA)
		return ("pa");
	else if (type == PB)
		return ("pb");
	else if (type == RA)
		return ("ra");
	else if (type == RB)
		return ("rb");
	else if (type == RR)
		return ("rr");
	else if (type == RRA)
		return ("rra");
	else if (type == RRB)
		return ("rrb");
	else if (type == RRR)
		return ("rrr");
	return ("");
}

int	cmd_str_totype(char *str)
{
	if (!ft_strncmp(str, "sa", 2))
		return (SA);
	else if (!ft_strncmp(str, "sb", 2))
		return (SB);
	else if (!ft_strncmp(str, "ss", 2))
		return (SS);
	else if (!ft_strncmp(str, "pa", 2))
		return (PA);
	else if (!ft_strncmp(str, "pb", 2))
		return (PB);
	else if (!ft_strncmp(str, "rra", 3))
		return (RRA);
	else if (!ft_strncmp(str, "rrb", 3))
		return (RRB);
	else if (!ft_strncmp(str, "rrr", 3))
		return (RRR);
	else if (!ft_strncmp(str, "ra", 2))
		return (RA);
	else if (!ft_strncmp(str, "rb", 2))
		return (RB);
	else if (!ft_strncmp(str, "rr", 2))
		return (RR);
	return (NIL);
}
