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

void	ft_print_stacks(t_stack *a, t_stack *b, char **argv)
{
	int i;

	if (ft_strcmp(argv[0], "-v") == 0 || ft_strcmp(argv[1], "-v") == 0)
	{
		ft_printf("Stack A :");
		while (a)
		{
			i = a->num;
			ft_printf("%d ", i);
			a = a->next;
		}
		ft_printf("\n");
		ft_printf("Stack B :");
		while (b)
		{
			i = b->num;
			ft_printf("%d ", i);
			b = b->next;
		}
		ft_printf("\n\n");
	}
}

void	ft_colors(char *str)
{
	write(1, "\033[035m", 6);
	ft_printf(">> %s <<\n", str);
	write(1, "\033[0m", 4);
}

void	ft_check_flags(char **argv, int *flag)
{
	if (argv && (*argv))
	{
		if (argv[1] && ft_strcmp(argv[*flag], "-v") == 0)
		{
			(*flag)++;
			if (argv[2] && ft_strcmp(argv[*flag], "-c") == 0)
				(*flag)++;
		}
	}
}
