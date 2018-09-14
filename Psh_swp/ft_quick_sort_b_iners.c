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

int		ft_booble_sort1(int *arr, int count)
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
	tmp = (count == 7) ? 4 : 13;
	return (arr[tmp]);
}

int		ft_find_midl_in_grup1(t_stack *stack, int count)
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
	return (ft_booble_sort1(to_sort, res));
}

void	ft_quick_sort_b_in(t_stack **b, int *midl, int *count)
{
	if (ft_grup_len(*b) == 25)
	{
		*midl = ft_find_midl_in_grup1(*b, 25);
		*count = 12;
	}
	if (ft_grup_len(*b) == 7)
	{
		*midl = ft_find_midl_in_grup1(*b, 7);
		*count = 3;
	}
}
