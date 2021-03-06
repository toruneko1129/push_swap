/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:20:24 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/09 15:03:46 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line_bonus.h"
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
void	solve(t_dlst **a, t_dlst **b);
int		check_issorted(t_dlst *stack_a, t_dlst *stack_b);
void	solve_size2_small(t_dlst **a);
void	solve_size3_small(t_dlst **a);
void	solve_size4_small(t_dlst **a, t_dlst **b);
void	solve_size5_small(t_dlst **a, t_dlst **b);
t_list	*solve_a(t_dlst **a, t_dlst **b, int left, int right);
t_list	*solve_b(t_dlst **a, t_dlst **b, int left, int right);
t_list	*solve_smallsize(t_dlst **a, t_dlst **b, int is_b, int size);
int		get_minval(t_dlst **a, t_dlst **b, int is_b, int size);
int		get_maxval(t_dlst **a, t_dlst **b, int is_b, int size);
t_list	*solve_size1(t_dlst **a, t_dlst **b, int is_b);
t_list	*solve_size2(t_dlst **a, t_dlst **b, int is_b);
t_list	*solve_size3(t_dlst **a, t_dlst **b, int is_b);
t_list	*solve_size_over3(t_dlst **a, t_dlst **b, int is_b, int size);
void	exec_command(int type, t_dlst **a, t_dlst **b);
int		exec_add_cmd(int type, t_dlst **a, t_dlst **b, t_list **ans);
void	print_cmd(int type);
void	print_all_cmd(t_list *ans);
void	print_checker_result(t_dlst *stack_a, t_dlst *stack_b);
void	print_error_exit(t_dlst **stack_a, t_dlst **stack_b);
void	free_all(t_dlst **stack_a, t_dlst **stack_b);
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
