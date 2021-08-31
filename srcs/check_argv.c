/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:46:37 by hkawakit          #+#    #+#             */
/*   Updated: 2021/08/31 23:59:16 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_isinteger(char *str)
{
	if (*str == '+' || *str == '-')
		++str;
	if (!*str)
		print_error();
	while (*str)
	{
		if (!ft_isdigit(*str))
			print_error();
		++str;
	}
}

static void	check_isrange_of_int(char *str)
{
	long	off;
	long	lim;
	long	res;

	off = ((long)INT_MAX + (*str == '-')) / 10;
	lim = ((long)INT_MAX + (*str == '-')) % 10;
	res = 0;
	if (*str == '+' || *str == '-')
		++str;
	while (*str && (res < off || (res == off && *str - '0' <= lim)))
		res = res * 10 + *(str++) - '0';
	if (*str)
		print_error();
}

static void	check_val_duplicate(int argc, char **argv)
{
	int		res;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		res = ft_atoi(argv[i]);
		j = 0;
		while (++j < i)
		{
			if (ft_atoi(argv[j]) == res)
				print_error();
		}
	}
}

void	check_argv(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	i = 0;
	while (++i < argc)
	{
		check_isinteger(argv[i]);
		check_isrange_of_int(argv[i]);
	}
	check_val_duplicate(argc, argv);
}
