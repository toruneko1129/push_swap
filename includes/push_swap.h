/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:20:24 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/03 21:28:02 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define NIL -1
# define TRUE 1
# define FALSE 0

typedef struct s_dlst
{
	int				val;
	struct s_dlst	*prev;
	struct s_dlst	*next;
}	t_dlst;

typedef enum e_cmd
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_cmd;

void	check_argv(int argc, char **argv);
void	check_init_failed_stack(t_dlst **stack_a, t_dlst **stack_b);
void	load_stack(int argc, char **argv, t_dlst **stack_a, t_dlst **stack_b);
void	check_init_failed_cmds(t_dlst **a, t_dlst **b, t_dlst **cmds);
void	solve(t_dlst **stack_a, t_dlst **stack_b, t_dlst **cmds);
int		check_issorted(t_dlst *stack_a, t_dlst *stack_b);
void	exec_command(int type, t_dlst **stack_a, t_dlst **stack_b);
void	free_all(t_dlst **stack_a, t_dlst **stack_b, t_dlst **cmds);
void	print_error_exit(void);
t_dlst	*dlstnew(int val);
void	dlstadd_front(t_dlst **lst, t_dlst *new);
int		dlstsize(t_dlst *dlst);
t_dlst	*dlstlast(t_dlst *dlst);
void	dlstadd_back(t_dlst **dlst, t_dlst *new);
void	dlstdelone(t_dlst **dlst);
void	dlstclear(t_dlst **dlst);
int		cmd_str_totype(char *str);
char	*cmd_type_tostr(int type);

#endif
