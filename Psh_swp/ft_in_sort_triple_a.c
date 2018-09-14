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

static void	ft_in1(t_stack **a, t_comand_list **comands)
{
	if ((*a)->grup == 0 && ft_grup_len(*a) == 3)
	{
		ft_rra(&(*a), &(*comands));
		ft_sa(&(*a), &(*comands));
		return ;
	}
	ft_ra(&(*a), &(*comands));
	ft_sa(&(*a), &(*comands));
	ft_rra(&(*a), &(*comands));
}

static void	ft_in2(t_stack **a, t_comand_list **comands)
{
	if ((*a)->grup == 0 && ft_grup_len(*a) == 3)
	{
		ft_rra(&(*a), &(*comands));
		return ;
	}
	ft_ra(&(*a), &(*comands));
	ft_sa(&(*a), &(*comands));
	ft_rra(&(*a), &(*comands));
	ft_sa(&(*a), &(*comands));
}

static void	ft_in3(t_stack **a, t_comand_list **comands)
{
	if ((*a)->grup == 0 && ft_grup_len(*a) == 3)
	{
		ft_sa(&(*a), &(*comands));
		ft_rra(&(*a), &(*comands));
		return ;
	}
	ft_sa(&(*a), &(*comands));
	ft_ra(&(*a), &(*comands));
	ft_sa(&(*a), &(*comands));
	ft_rra(&(*a), &(*comands));
	ft_sa(&(*a), &(*comands));
}

static void	ft_in4(t_stack **a, t_comand_list **comands)
{
	if ((*a)->grup == 0 && ft_grup_len(*a) == 3)
	{
		ft_ra(&(*a), &(*comands));
		return ;
	}
	ft_sa(&(*a), &(*comands));
	ft_ra(&(*a), &(*comands));
	ft_sa(&(*a), &(*comands));
	ft_rra(&(*a), &(*comands));
}

void		ft_in_sort_triple_a(t_stack **a, t_comand_list **comands)
{
	if ((*a)->num < (*a)->next->num && (*a)->next->num >
		(*a)->next->next->num && (*a)->num < (*a)->next->next->num)
		ft_in1(&(*a), &(*comands));
	if ((*a)->num > (*a)->next->num && (*a)->next->num <
		(*a)->next->next->num && (*a)->num < (*a)->next->next->num)
		ft_sa(&(*a), &(*comands));
	if ((*a)->num < (*a)->next->num && (*a)->next->num >
		(*a)->next->next->num && (*a)->num > (*a)->next->next->num)
		ft_in2(&(*a), &(*comands));
	if ((*a)->num > (*a)->next->num && (*a)->next->num >
		(*a)->next->next->num && (*a)->num > (*a)->next->next->num)
		ft_in3(&(*a), &(*comands));
	if ((*a)->num > (*a)->next->num && (*a)->next->num <
		(*a)->next->next->num && (*a)->num > (*a)->next->next->num)
		ft_in4(&(*a), &(*comands));
	(*a)->grup = -1;
	(*a)->next->grup = -1;
	if ((*a)->next->next)
		(*a)->next->next->grup = -1;
}
