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

static	void	ft_push_double(t_stack **a,
	t_stack **b, t_comand_list **comands)
{
	if ((*b)->num < (*b)->next->num)
		ft_sb(&(*b), &(*comands));
	ft_pa(&(*a), &(*b), &(*comands));
	ft_pa(&(*a), &(*b), &(*comands));
	(*a)->grup = -1;
	(*a)->next->grup = -1;
}

static	void	ft_init_variables_b(t_stack **b,
	int *midl, int *count, int *midl_s)
{
	*count = ft_grup_len(*b);
	*midl_s = *count;
	*midl = ft_find_midl_in_grup(*b, *count);
	*count = *count % 2 != 0 ? (*count + 1) / 2 : *count / 2;
}

static	void	ft_eq_r_lower_three_b(t_stack **a, t_stack **b,
	t_comand_list **comands, int *grp)
{
	if (ft_grup_len(*b) == 3)
	{
		ft_in_sort_triple_b(&(*a), &(*b), &(*comands));
		if ((*b) && *grp == (*b)->grup)
			ft_smart_triple_b(&(*a), &(*b), &(*comands));
	}
	else if (ft_grup_len(*b) == 2)
		ft_push_double(&(*a), &(*b), &(*comands));
	else
	{
		ft_pa(&(*a), &(*b), &(*comands));
		(*a)->grup = -1;
	}
}

static void		ft_magic(t_stack **b, t_stack **a, t_comand_list **com, int grp)
{
	while ((*b) && (*b)->next && ft_get_last(*b)->grup == grp - 1 &&
	ft_get_last(*b)->grup != 1)
		ft_rrb(&(*b), &(*com));
	ft_quick_sort_a(&(*a), &(*b), &(*com));
}

void			ft_quick_sort_b(t_stack **a,
	t_stack **b, t_comand_list **comands)
{
	int midl;
	int count;
	int grp;
	int lowest;
	int midl_s;

	lowest = ft_find_lowest_in_row(*b);
	grp = (*b)->grup;
	if (ft_grup_len(*b) <= 3)
		ft_eq_r_lower_three_b(&(*a), &(*b), &(*comands), &grp);
	ft_check_revers(&(*a), &(*b), &(*comands));
	if (!(*b))
		return ;
	ft_init_variables_b(&(*b), &midl, &count, &midl_s);
	grp = ft_new_grup(*a, *b);
	ft_quick_sort_b_in(&(*b), &midl, &count);
	while (count)
		if ((*b) && (*b)->num >= midl && count--)
			ft_swap_from_b(&(*a), &(*b), &(*comands), grp);
		else if ((*b) && (*b)->num < midl && (*b)->grup == (grp - 1))
			ft_rb(&(*b), &(*comands));
	ft_magic(&(*b), &(*a), &(*comands), grp);
}
