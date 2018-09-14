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

static void	ft_in1(t_stack **a, t_stack **b,
	t_comand_list **comands)
{
	if (ft_grup_len(*b) == 3 && (*b)->grup == ft_get_last(*b)->grup)
	{
		ft_rrb(&(*b), &(*comands));
		ft_rrb(&(*b), &(*comands));
		return ;
	}
	ft_rb(&(*b), &(*comands));
	ft_sb(&(*b), &(*comands));
	ft_pa(&(*a), &(*b), &(*comands));
	ft_pa(&(*a), &(*b), &(*comands));
	if ((*b)->next)
		ft_rrb(&(*b), &(*comands));
	ft_pa(&(*a), &(*b), &(*comands));
}

static void	ft_in2(t_stack **a, t_stack **b,
	t_comand_list **comands)
{
	if (ft_grup_len(*b) == 3 && (*b)->grup == ft_get_last(*b)->grup)
	{
		ft_rb(&(*b), &(*comands));
		return ;
	}
	ft_rb(&(*b), &(*comands));
	ft_pa(&(*a), &(*b), &(*comands));
	ft_pa(&(*a), &(*b), &(*comands));
	if ((*b)->next)
		ft_rrb(&(*b), &(*comands));
	ft_pa(&(*a), &(*b), &(*comands));
}

static void	ft_in3(t_stack **a, t_stack **b,
	t_comand_list **comands)
{
	if (ft_grup_len(*b) == 3 && (*b)->grup == ft_get_last(*b)->grup)
	{
		ft_rrb(&(*b), &(*comands));
		return ;
	}
	ft_pa(&(*a), &(*b), &(*comands));
	ft_sb(&(*b), &(*comands));
	ft_pa(&(*a), &(*b), &(*comands));
	ft_sa(&(*a), &(*comands));
	ft_pa(&(*a), &(*b), &(*comands));
}

void		ft_in_sort_triple_b(t_stack **a,
	t_stack **b, t_comand_list **comands)
{
	if ((*b)->num < (*b)->next->num && (*b)->next->num <
	(*b)->next->next->num && (*b)->num < (*b)->next->next->num)
		ft_in1(&(*a), &(*b), &(*comands));
	else if ((*b)->num < (*b)->next->num && (*b)->next->num >
	(*b)->next->next->num && (*b)->num < (*b)->next->next->num)
		ft_in2(&(*a), &(*b), &(*comands));
	else if ((*b)->num > (*b)->next->num && (*b)->next->num <
	(*b)->next->next->num && (*b)->num < (*b)->next->next->num)
		ft_in3(&(*a), &(*b), &(*comands));
	(*a)->grup = -1;
	(*a)->next->grup = -1;
	if ((*a)->next->next)
		(*a)->next->next->grup = -1;
}
