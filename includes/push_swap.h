/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:20:24 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/01 23:15:16 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_dlst
{
	int				val;
	struct s_dlst	*prev;
	struct s_dlst	*next;
}	t_dlst;

void	check_argv(int argc, char **argv);
void	check_init_failed(t_dlst *stack_a, t_dlst *stack_b);
t_dlst	*dlstnew(int val);
void	dlstadd_front(t_dlst **lst, t_dlst *new);
void	free_all(t_dlst *stack_a, t_dlst *stack_b);
void	print_error_exit(void);

#endif
