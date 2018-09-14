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

static	void	ft_sort_triple_a(t_stack **a, t_comand_list **com)
{
	if ((*a)->num < (*a)->next->num && (*a)->num < (*a)->next->next->num
	&& (*a)->next->next->num < (*a)->next->num)
	{
		ft_rra(&(*a), &(*com));
		ft_sa(&(*a), &(*com));
	}
	else if ((*a)->num > (*a)->next->num && (*a)->num < (*a)->next->next->num
	&& (*a)->next->next->num > (*a)->next->num)
		ft_sa(&(*a), &(*com));
	else if ((*a)->num < (*a)->next->num && (*a)->num > (*a)->next->next->num
	&& (*a)->next->next->num < (*a)->next->num)
		ft_rra(&(*a), &(*com));
	else if ((*a)->num > (*a)->next->num && (*a)->num > (*a)->next->next->num
	&& (*a)->next->next->num < (*a)->next->num)
	{
		ft_sa(&(*a), &(*com));
		ft_rra(&(*a), &(*com));
	}
	else if ((*a)->num > (*a)->next->num && (*a)->num > (*a)->next->next->num
	&& (*a)->next->next->num > (*a)->next->num)
	{
		ft_rra(&(*a), &(*com));
		ft_rra(&(*a), &(*com));
	}
}

static	void	ft_sort_triple_b(t_stack **b, t_comand_list **com)
{
	if ((*b)->num < (*b)->next->num && (*b)->num < (*b)->next->next->num
	&& (*b)->next->next->num < (*b)->next->num)
		ft_rb(&(*b), &(*com));
	else if ((*b)->num > (*b)->next->num && (*b)->num < (*b)->next->next->num
	&& (*b)->next->next->num > (*b)->next->num)
		ft_rrb(&(*b), &(*com));
	else if ((*b)->num < (*b)->next->num && (*b)->num > (*b)->next->next->num
	&& (*b)->next->next->num < (*b)->next->num)
		ft_sb(&(*b), &(*com));
	else if ((*b)->num < (*b)->next->num && (*b)->num < (*b)->next->next->num
	&& (*b)->next->next->num > (*b)->next->num)
	{
		ft_sb(&(*b), &(*com));
		ft_rrb(&(*b), &(*com));
	}
	else if ((*b)->num > (*b)->next->num && (*b)->num > (*b)->next->next->num
	&& (*b)->next->next->num > (*b)->next->num)
	{
		ft_rrb(&(*b), &(*com));
		ft_sb(&(*b), &(*com));
	}
}

static	void	ft_sort(t_stack **a, t_stack **b, t_comand_list **com, int flag)
{
	if (flag == 1)
	{
		if (ft_grup_len(*a) == 3)
			ft_sort_triple_a(&(*a), &(*com));
		if (ft_grup_len(*a) == 2)
			if ((*a)->num > (*a)->next->num)
				ft_sa(&(*a), &(*com));
	}
	else
	{
		if (ft_grup_len(*a) == 3)
			ft_sort_triple_a(&(*a), &(*com));
		if (ft_grup_len(*a) == 2)
			if ((*a)->num > (*a)->next->num)
				ft_sa(&(*a), &(*com));
		if (ft_grup_len(*b) == 3)
			ft_sort_triple_b(&(*b), &(*com));
		if (ft_grup_len(*b) == 2)
			if ((*b)->num < (*b)->next->num)
				ft_sb(&(*b), &(*com));
	}
}

static	void	ft_sort_with_b(t_stack **a, t_stack **b, t_comand_list **com)
{
	int midl;
	int count;
	int midl_s;

	count = ft_grup_len(*a);
	midl = ft_find_midl_in_grup(*a, count);
	midl_s = count;
	count = count / 2;
	while (count)
		if ((*a)->num <= midl)
		{
			if ((*a)->num == midl)
				ft_ra(&(*a), &(*com));
			else if ((*a)->num < midl)
			{
				ft_pb(&(*b), &(*a), &(*com));
				count--;
			}
		}
		else if ((*a)->num > midl)
			ft_ra(&(*a), &(*com));
	ft_sort(&(*a), &(*b), &(*com), 0);
	count = ft_grup_len(*b);
	while (count--)
		ft_pa(&(*a), &(*b), &(*com));
}

void			ft_easy_sort(t_stack **a, t_stack **b, t_comand_list **com)
{
	if (ft_grup_len(*a) > 3)
		ft_sort_with_b(&(*a), &(*b), &(*com));
	else
		ft_sort(&(*a), &(*b), &(*com), 1);
	ft_print_exit(&(*a), &(*b), &(*com));
}
