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

static	void	ft_eq_r_lower_three_a(t_stack **a,
	t_stack **b, t_comand_list **comands)
{
	if (ft_grup_len(*a) == 3)
		ft_in_sort_triple_a(&(*a), &(*comands));
	else if (ft_grup_len(*a) == 2)
	{
		if ((*a)->num > (*a)->next->num)
			ft_sa(&(*a), &(*comands));
		(*a)->grup = -1;
		(*a)->next->grup = -1;
	}
	else if (ft_grup_len(*a) == 1)
		(*a)->grup = -1;
	if (*b)
		ft_quick_sort_b(&(*a), &(*b), &(*comands));
}

static	void	ft_swap_from_a(t_stack **a, t_stack **b,
	t_comand_list **comands, int grp)
{
	ft_pb(&(*b), &(*a), &(*comands));
	(*b)->grup = grp;
	if ((*b) && (*b)->next && (*b)->num <
	(*b)->next->num && ft_grup_len(*b) <= 3)
		ft_sb(&(*b), &(*comands));
	ft_swap_from_a_in(&(*comands), &(*b), (*a), (*b));
}

static	void	ft_init_variables_a(t_stack **a,
	int *midl, int *count, int *midl_s)
{
	*count = ft_grup_len(*a);
	*midl_s = *count;
	*midl = ft_find_midl_in_grup(*a, *count);
	*count = *count % 2 != 0 ? (*count + 1) / 2 : *count / 2;
}

static	void	ft_move_rra_back(t_stack **a,
	t_comand_list **comands, int *grup)
{
	while (ft_get_last(*a)->grup == *grup && ft_get_last(*a)->grup != 0
	&& ft_get_last(*a)->grup != -1)
		ft_rra(&(*a), &(*comands));
}

void			ft_quick_sort_a(t_stack **a,
	t_stack **b, t_comand_list **comands)
{
	int midl;
	int count;
	int grp;
	int midl_s;
	int grup;

	ft_quick_sort_a_in(&(*a), &(*b), &(*comands));
	if (ft_grup_len(*a) <= 3)
		return (ft_eq_r_lower_three_a(&(*a), &(*b), &(*comands)));
	ft_init_variables_a(&(*a), &midl, &count, &midl_s);
	grup = (*a)->grup;
	grp = ft_new_grup(*a, *b);
	ft_quick_sort_a_in1(&(*a), &(*b), &(*comands), &midl);
	while (count)
		if ((*a)->num <= midl)
			if ((*a)->num < midl && count--)
				ft_swap_from_a(&(*a), &(*b), &(*comands), grp);
			else if ((*a)->num == midl && midl_s % 2 != 0 && count--)
				ft_swap_from_a(&(*a), &(*b), &(*comands), grp);
			else
				ft_ra(&(*a), &(*comands));
		else if ((*a)->num > midl && (*a)->grup == grup)
			ft_ra(&(*a), &(*comands));
	ft_move_rra_back(&(*a), &(*comands), &grup);
	ft_quick_sort_a(&(*a), &(*b), &(*comands));
}
