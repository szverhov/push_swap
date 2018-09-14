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

#include "./push_swap.h"

int		ft_count_of_biggest(t_stack *stack, int midl)
{
	int res;
	int grup;

	grup = stack->grup;
	res = 0;
	while (stack && stack->grup == grup)
	{
		if (stack->num > midl)
			res++;
		stack = stack->next;
	}
	return (res);
}

int		ft_count_of_lowest(t_stack *stack, int midl)
{
	int res;
	int grup;

	grup = stack->grup;
	res = 0;
	while (stack && stack->grup == grup)
	{
		if (stack->num < midl)
			res++;
		stack = stack->next;
	}
	return (res);
}

int		ft_find_lowest_in_row(t_stack *stack)
{
	int res;
	int grup;

	grup = stack->grup;
	res = 2147483647;
	while (stack && stack->grup == grup)
	{
		if (stack->num < res)
			res = stack->num;
		stack = stack->next;
	}
	return (res);
}

int		ft_find_biggest_in_row(t_stack *stack)
{
	int res;
	int grup;

	grup = stack->grup;
	res = -2147483648;
	while (stack && stack->grup == grup)
	{
		if (stack->num > res)
			res = stack->num;
		stack = stack->next;
	}
	return (res);
}

void	ft_print_exit(t_stack **a, t_stack **b, t_comand_list **com)
{
	ft_remove_comands(&(*com));
	ft_write_comands(*com);
	ft_clean_up(&(*a), &(*b), &(*com));
}
