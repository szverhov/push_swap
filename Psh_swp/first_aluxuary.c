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

t_stack	*ft_get_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int		ft_new_grup(t_stack *a, t_stack *b)
{
	int grp;

	grp = 0;
	while (a)
	{
		if (a->grup > grp)
			grp = a->grup;
		a = a->next;
	}
	while (b)
	{
		if (b->grup > grp)
			grp = b->grup;
		b = b->next;
	}
	return (grp + 1);
}

int		ft_find_midl_in_grup(t_stack *stack, int count)
{
	int res;
	int to_sort[count];

	res = 0;
	while (count)
	{
		to_sort[res] = stack->num;
		stack = stack->next;
		res++;
		count--;
	}
	return (ft_booble_sort(to_sort, res));
}

int		ft_booble_sort(int *arr, int count)
{
	int tmp;
	int i;

	i = 0;
	tmp = 0;
	while (i < count)
	{
		if (i + 1 < count && arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 0;
			continue ;
		}
		i++;
	}
	i = 0;
	return (arr[count / 2]);
}

int		ft_grup_len(t_stack *stack)
{
	int res;
	int current_grp;

	res = 0;
	if (stack)
		current_grp = stack->grup;
	while (stack && stack->grup == current_grp)
	{
		res++;
		stack = stack->next;
	}
	return (res);
}
