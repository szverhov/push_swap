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

#include "checker.h"

static int		ft_is_it_int(char *str)
{
	int i;

	if (str[0] == '-' && ft_strlen_int(str) == 11)
		if (ft_strcmp(str, "-2147483648") > 0)
			return (0);
	if ((str[0] == '+' && ft_strlen_int(str) == 11) ||
	(ft_strlen_int(str) == 10 && (str[0] != '-' && str[0] != '+')))
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

static int		ft_check_data(char **argv, int flag)
{
	int len;
	int i;
	int j;

	i = -1;
	while (argv[++i])
	{
		j = i + 1;
		while (argv[j])
			if (argv[j] != 0 && ft_strcmp_spec(argv[i], argv[j++]) == 0)
				return (0);
	}
	while (argv[flag])
	{
		if (!ft_strcmp(argv[flag], "-") || !ft_strcmp(argv[flag], "+"))
			return (0);
		len = (argv[flag][0] == '-' || argv[flag][0] == '+') ? 11 : 10;
		if (ft_strlen_int(argv[flag]) > len || ft_is_it_int(argv[flag]) == 0)
			return (0);
		flag++;
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
	if (flag == 0)
	{
		while (i--)
			free(argv[j++]);
		free(argv);
	}
	exit(0);
}

void			ft_write_comands(t_comand_list *com)
{
	while (com->prev)
		com = com->prev;
	com = com->next;
	while (com)
	{
		ft_printf("%s \n", com->comand);
		com = com->next;
	}
}

int				ft_checker(int argc, char **argv, int flag)
{
	int				i;
	t_stack			*stack;
	t_comand_list	*list;
	char			*str;
	int				free_arg;

	free_arg = flag;
	ft_check_flags(argv, &flag);
	if (!argv || !(*argv) || argv[flag] == 0 || ft_check_data(argv, flag) == 0)
		ft_data_error(argv, free_arg);
	argc = ft_count_of_words(argv);
	i = flag;
	if (!(stack = ft_new_node(ft_atoi(argv[i++]), 0)))
		return (1);
	while (i < argc)
		if (!(ft_add_node(&stack, ft_atoi(argv[i++]), 0)))
			return (1);
	ft_init_comands(&list);
	if (ft_read_comands(&list, &str) == 0)
		clean_up(&stack, 0, &list);
	ft_sort(&stack, &list, argv);
	if (free_arg == 0)
		ft_clean_prototypes(argv);
	clean_up(&stack, 0, &list);
	return (0);
}
