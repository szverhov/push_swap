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

void			ft_quick_sort_a_in(t_stack **a,
	t_stack **b, t_comand_list **comands)
{
	if ((*a)->grup != -1 && ft_grup_len(*a) > 3)
		ft_check_last_nums(&(*a), &(*b), &(*comands));
}

void			ft_quick_sort_a_in1(t_stack **a,
	t_stack **b, t_comand_list **comands, int *midl)
{
	if (!(*b) && (*a)->grup == 0)
		ft_magic_for_first_division(&(*a), &(*midl), &(*comands));
}

void			ft_check_last_nums_in(t_stack *tmp_a,
	t_stack *tmp_b, int *flag, t_stack **a)
{
	while (tmp_a)
	{
		if (tmp_a->num > ft_get_last_in_row(*a)->num && tmp_a->num
		< ft_get_last_in_row(*a)->next->num)
			*flag = 1;
		tmp_a = tmp_a->next;
	}
	while (tmp_b)
	{
		if (tmp_b->num > ft_get_last_in_row(*a)->num && tmp_b->num
		< ft_get_last_in_row(*a)->next->num)
			*flag = 1;
		tmp_b = tmp_b->next;
	}
}

void			ft_swap_from_a_in(t_comand_list **c,
	t_stack **b, t_stack *tmp_a, t_stack *tmp_b)
{
	if ((*b)->grup == 1 && (*b)->next)
	{
		if (ft_get_last(*b)->num > (*b)->num)
		{
			while (tmp_a)
			{
				if (tmp_a->num < (*b)->num && tmp_a->num > ft_get_last(*b)->num)
					return ;
				tmp_a = tmp_a->next;
			}
			while (tmp_b)
			{
				if (tmp_b->num < (*b)->num && tmp_b->num > ft_get_last(*b)->num)
					return ;
				tmp_b = tmp_b->next;
			}
			ft_rb(&(*b), &(*c));
		}
	}
}

t_stack			*ft_get_last_in_row(t_stack *stack)
{
	int grup;

	grup = stack->grup;
	while (stack->next && stack->next->grup == grup)
		stack = stack->next;
	return (stack);
}
