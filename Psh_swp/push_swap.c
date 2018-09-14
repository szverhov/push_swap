/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szverhov <szverhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:31:43 by szverhov          #+#    #+#             */
/*   Updated: 2017/11/03 12:27:15 by szverhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_is_it_int(char *str)
{
	int i;

	if (str[0] == '-' && ft_str_len(str) == 11)
		if (ft_strcmp(str, "-2147483648") > 0)
			return (0);
	if ((str[0] == '+' && ft_str_len(str) == 11) ||
	(ft_str_len(str) == 10 && (str[0] != '-' && str[0] != '+')))
		if (ft_strcmp(str, "2147483647") > 0)
			return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int		ft_check_data(char **argv, int flag, t_stack **b)
{
	int i;
	int len;
	int j;

	*b = 0;
	i = (flag == 1) ? -1 : 0;
	while (argv[++i])
	{
		j = i + 1;
		while (argv[j])
			if (argv[j] != 0 && ft_strcmp_spec(argv[i], argv[j++]) == 0)
				return (0);
	}
	i = (flag == 1) ? -1 : 0;
	while (argv[++i])
	{
		if (!ft_strcmp(argv[i], "-") || !ft_strcmp(argv[i], "+"))
			return (0);
		len = (argv[i][0] == '-' || argv[i][0] == '+') ? 11 : 10;
		if (ft_str_len(argv[i]) > len || ft_is_it_int(argv[i]) == 0)
		{
			return (0);
		}
	}
	return (1);
}

static void		ft_data_error(char **argv, int flag)
{
	int		i;
	int		j;

	ft_printf("%s\n", "Error");
	if (!argv || !(*argv))
	{
		if (argv)
			free(argv);
		exit(0);
	}
	i = ft_count_of_words(argv) + 1;
	j = 0;
	if (flag == 1)
	{
		while (i--)
			free(argv[j++]);
		free(argv);
	}
	exit(0);
}

int				ft_push_swap(char **argv, int argc, int flag)
{
	t_stack			*stack;
	int				i;
	t_comand_list	*com;
	t_stack			*b;

	if (!argv || !(*argv) || ft_check_data(argv, flag, &b) == 0)
		ft_data_error(argv, flag);
	argc = ft_count_of_words(argv);
	i = (flag == 1) ? 0 : 1;
	if (!(stack = ft_new_node(ft_atoi(argv[i++]), 0)))
		return (0);
	while (i < argc)
		if (!(ft_add_node(&stack, ft_atoi(argv[i++]), 0)))
			return (0);
	if (flag == 1)
		ft_clean_argv(argv);
	if (ft_is_sorted(&stack) == 1)
		return (1);
	ft_init_comands(&com);
	if (ft_grup_len(stack) <= 6)
		ft_easy_sort(&stack, &b, &com);
	ft_quick_sort_a(&stack, &b, &com);
	ft_print_exit(&stack, &b, &com);
	return (1);
}
