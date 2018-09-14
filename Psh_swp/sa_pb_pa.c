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

void		ft_pa(t_stack **a, t_stack **b, t_comand_list **c)
{
	t_stack *new_head;
	t_stack *tmp;

	if (!a || !(*a) || !b || !(*b))
		ft_clean_up(&(*a), &(*b), &(*c));
	if (!(new_head = ft_new_node((*b)->num, (*b)->grup)))
		ft_clean_up(&(*a), &(*b), &(*c));
	new_head->next = (*a);
	(*a) = new_head;
	tmp = (*b)->next;
	free((*b));
	*b = tmp;
	if (!ft_add_comand(&(*c), "pa\n"))
		ft_clean_up(&(*a), &(*b), &(*c));
}

void		ft_pb(t_stack **b, t_stack **a, t_comand_list **c)
{
	t_stack *new_head;
	t_stack *tmp;

	if (!b || !a || !(*a))
		ft_clean_up(&(*a), &(*b), &(*c));
	if (!(new_head = ft_new_node((*a)->num, (*a)->grup)))
		ft_clean_up(&(*a), &(*b), &(*c));
	new_head->next = (*b);
	(*b) = new_head;
	tmp = (*a)->next;
	free(*a);
	*a = tmp;
	if (!ft_add_comand(&(*c), "pb\n"))
		ft_clean_up(&(*a), &(*b), &(*c));
}

void		ft_sa(t_stack **stack, t_comand_list **c)
{
	int i;

	if (stack == 0 || *stack == 0)
		ft_clean_up(&(*stack), 0, &(*c));
	if ((*stack)->next)
	{
		i = (*stack)->num;
		(*stack)->num = (*stack)->next->num;
		(*stack)->next->num = i;
	}
	if (!ft_add_comand(&(*c), "sa\n"))
		ft_clean_up(&(*stack), 0, &(*c));
}

void		ft_check_last_nums(t_stack **a,
	t_stack **b, t_comand_list **comands)
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	int		flag;

	tmp_a = *a;
	tmp_b = *b;
	flag = 0;
	if ((*a)->grup == -1)
		return ;
	if (ft_get_last_in_row(*a)->next && ft_get_last_in_row(*a)->next->grup == -1
	&& ft_get_last_in_row(*a)->num < ft_get_last_in_row(*a)->next->num)
	{
		ft_check_last_nums_in(*a, *b, &flag, &(*a));
		if (flag == 0)
		{
			ft_get_last_in_row(*a)->grup = -1;
			if (ft_grup_len(*a) > 3)
				ft_check_last_nums(&(*a), &(*b), &(*comands));
		}
	}
}
