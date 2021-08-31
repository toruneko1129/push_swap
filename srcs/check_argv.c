/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:46:37 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/01 02:13:56 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_isinteger(char *str)
{
	if (*str == '+' || *str == '-')
		++str;
	if (!*str)
		print_error_exit();
	while (*str)
	{
		if (!ft_isdigit(*str))
			print_error_exit();
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
		print_error_exit();
}

static int	*get_intarr_from_argv(int argc, char **argv)
{
	int		*arr;
	int		i;

	arr = (int *)malloc((argc - 1) * sizeof(int));
	if (arr == NULL)
		print_error_exit();
	i = 0;
	while (++i < argc)
		*(arr + i - 1) = ft_atoi(argv[i]);
	return (arr);
}

static void	check_val_duplicate(int argc, int *arr)
{
	int		i;
	int		j;

	i = -1;
	while (++i < argc - 1)
	{
		j = -1;
		while (++j < i)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				print_error_exit();
			}
		}
	}
}

int		*check_argv(int argc, char **argv)
{
	int		*arr;
	int		i;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	i = 0;
	while (++i < argc)
	{
		check_isinteger(argv[i]);
		check_isrange_of_int(argv[i]);
	}
	arr = get_intarr_from_argv(argc, argv);
	check_val_duplicate(argc, arr);
	for (int j = 0; j < argc - 1; ++j)
	{
		ft_putnbr_fd(arr[j], 1);
		ft_putchar_fd('\n', 1);
	}
	return (arr);
}
