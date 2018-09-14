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

void		ft_sa(t_stack **a, t_stack **b, t_comand_list **c, char **t)
{
	int i;

	(*c) = (*c);
	(*b) = (*b);
	if ((*a) && (*a)->next)
	{
		i = (*a)->num;
		(*a)->num = (*a)->next->num;
		(*a)->next->num = i;
	}
	if (t && (ft_strcmp(t[1], "-c") == 0 || ft_strcmp(t[2], "-c") == 0))
		ft_colors("sa");
	if (t)
		ft_print_stacks(*a, *b, t);
}

void		ft_sb(t_stack **a, t_stack **b, t_comand_list **c, char **t)
{
	int i;

	(*c) = (*c);
	(*a) = (*a);
	if ((*b) && (*b)->next)
	{
		i = (*b)->num;
		(*b)->num = (*b)->next->num;
		(*b)->next->num = i;
	}
	if (t && (ft_strcmp(t[1], "-c") == 0 || ft_strcmp(t[2], "-c") == 0))
		ft_colors("sb");
	if (t)
		ft_print_stacks(*a, *b, t);
}

void		ft_ss(t_stack **a, t_stack **b, t_comand_list **c, char **t)
{
	ft_sa(&(*a), &(*b), &(*c), 0);
	ft_sb(&(*a), &(*b), &(*c), 0);
	if (ft_strcmp(t[1], "-c") == 0 || ft_strcmp(t[2], "-c") == 0)
		ft_colors("ss");
	ft_print_stacks(*a, *b, t);
}

void		ft_rr(t_stack **a, t_stack **b, t_comand_list **c, char **t)
{
	ft_ra(&(*a), &(*b), &(*c), 0);
	ft_rb(&(*a), &(*b), &(*c), 0);
	if (ft_strcmp(t[1], "-c") == 0 || ft_strcmp(t[2], "-c") == 0)
		ft_colors("rr");
	ft_print_stacks(*a, *b, t);
}

void		ft_rrr(t_stack **a, t_stack **b, t_comand_list **c, char **t)
{
	ft_rra(&(*a), &(*b), &(*c), 0);
	ft_rrb(&(*a), &(*b), &(*c), 0);
	if (ft_strcmp(t[1], "-c") == 0 || ft_strcmp(t[2], "-c") == 0)
		ft_colors("rrr");
	ft_print_stacks(*a, *b, t);
}
