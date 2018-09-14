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

void		ft_ra(t_stack **a, t_stack **b, t_comand_list **c, char **t)
{
	t_stack *tmp;

	if (!a || !(*a) || !(*a)->next)
	{
		if (t && (ft_strcmp(t[1], "-c") == 0 ||
		ft_strcmp(t[2], "-c") == 0))
			ft_colors("ra");
		if (t)
			ft_print_stacks(*a, *b, t);
		return ;
	}
	tmp = (*a);
	if (!(ft_add_node(&(*a), (*a)->num, (*a)->grup)))
		clean_up(&(*a), &(*b), &(*c));
	(*a) = (*a)->next;
	free(tmp);
	tmp = 0;
	if (t && (ft_strcmp(t[1], "-c") == 0 ||
	ft_strcmp(t[2], "-c") == 0))
		ft_colors("ra");
	if (t)
		ft_print_stacks(*a, *b, t);
}

void		ft_rra(t_stack **a, t_stack **b, t_comand_list **c, char **t)
{
	t_stack *tmp;
	t_stack *new_head;

	if (!a || !(*a) || !(*a)->next)
	{
		if (t && (ft_strcmp(t[1], "-c") == 0 || ft_strcmp(t[2], "-c") == 0))
			ft_colors("rra");
		if (t)
			ft_print_stacks(*a, *b, t);
		return ;
	}
	tmp = (*a);
	while (tmp->next->next)
		tmp = tmp->next;
	if (!(new_head = ft_new_node(tmp->next->num, tmp->next->grup)))
		clean_up(&(*a), &(*b), &(*c));
	free(tmp->next);
	tmp->next = 0;
	new_head->next = (*a);
	(*a) = new_head;
	if (t && (ft_strcmp(t[1], "-c") == 0 || ft_strcmp(t[2], "-c") == 0))
		ft_colors("rra");
	if (t)
		ft_print_stacks(*a, *b, t);
}

void		ft_rb(t_stack **a, t_stack **b, t_comand_list **c, char **t)
{
	t_stack *tmp;

	if (!b || !(*b) || !(*b)->next)
	{
		if (t && (ft_strcmp(t[1], "-c") == 0 || ft_strcmp(t[2], "-c") == 0))
			ft_colors("rb");
		if (t)
			ft_print_stacks(*a, *b, t);
		return ;
	}
	tmp = (*b);
	if (!(ft_add_node(&(*b), (*b)->num, (*b)->grup)))
		clean_up(&(*a), &(*b), &(*c));
	(*b) = (*b)->next;
	free(tmp);
	if (t && (ft_strcmp(t[1], "-c") == 0 || ft_strcmp(t[2], "-c") == 0))
		ft_colors("rb");
	if (t)
		ft_print_stacks(*a, *b, t);
}

void		ft_rrb(t_stack **a, t_stack **b, t_comand_list **c, char **t)
{
	t_stack *tmp;
	t_stack *new_head;

	if (!b || !(*b) || !(*b)->next)
	{
		if (t && (ft_strcmp(t[1], "-c") == 0 || ft_strcmp(t[2], "-c") == 0))
			ft_colors("rrb");
		if (t)
			ft_print_stacks(*a, *b, t);
		return ;
	}
	tmp = (*b);
	while (tmp->next->next)
		tmp = tmp->next;
	if (!(new_head = ft_new_node(tmp->next->num, tmp->next->grup)))
		clean_up(&(*a), &(*b), &(*c));
	free(tmp->next);
	tmp->next = 0;
	new_head->next = (*b);
	(*b) = new_head;
	if (t && (ft_strcmp(t[1], "-c") == 0 || ft_strcmp(t[2], "-c") == 0))
		ft_colors("rrb");
	if (t)
		ft_print_stacks(*a, *b, t);
}

void		ft_pa(t_stack **a, t_stack **b, t_comand_list **c, char **t)
{
	t_stack *new_head;
	t_stack *tmp;

	if (!b || !(*b))
	{
		if (ft_strcmp(t[1], "-c") == 0 || ft_strcmp(t[2], "-c") == 0)
			ft_colors("pa");
		ft_print_stacks(*a, *b, t);
		return ;
	}
	if (!(new_head = ft_new_node((*b)->num, (*b)->grup)))
		clean_up(&(*a), &(*b), &(*c));
	new_head->next = (*a);
	(*a) = new_head;
	tmp = (*b)->next;
	free((*b));
	*b = tmp;
	if (ft_strcmp(t[1], "-c") == 0 || ft_strcmp(t[2], "-c") == 0)
		ft_colors("pa");
	ft_print_stacks(*a, *b, t);
}
