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

void		ft_ra(t_stack **stack, t_comand_list **c)
{
	t_stack *tmp;

	if (stack == 0 || *stack == 0)
		ft_clean_up(&(*stack), 0, &(*c));
	tmp = (*stack);
	if (!ft_add_node(&(*stack), (*stack)->num, (*stack)->grup))
		ft_clean_up(&(*stack), 0, &(*c));
	(*stack) = (*stack)->next;
	free(tmp);
	tmp = 0;
	if (!ft_add_comand(&(*c), "ra\n"))
		ft_clean_up(&(*stack), 0, &(*c));
}

void		ft_rra(t_stack **stack, t_comand_list **c)
{
	t_stack *tmp;
	t_stack *new_head;

	if (stack == 0 || *stack == 0)
		ft_clean_up(&(*stack), 0, &(*c));
	tmp = (*stack);
	while (tmp->next->next)
		tmp = tmp->next;
	if (!(new_head = ft_new_node(tmp->next->num, tmp->next->grup)))
		ft_clean_up(&(*stack), 0, &(*c));
	free(tmp->next);
	tmp->next = 0;
	new_head->next = (*stack);
	(*stack) = new_head;
	if (!ft_add_comand(&(*c), "rra\n"))
		ft_clean_up(&(*stack), 0, &(*c));
}

void		ft_sb(t_stack **stack, t_comand_list **c)
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
	if (!ft_add_comand(&(*c), "sb\n"))
		ft_clean_up(&(*stack), 0, &(*c));
}

void		ft_rb(t_stack **stack, t_comand_list **c)
{
	t_stack *tmp;

	if (stack == 0 || *stack == 0)
		ft_clean_up(&(*stack), 0, &(*c));
	tmp = (*stack);
	if (!ft_add_node(&(*stack), (*stack)->num, (*stack)->grup))
		ft_clean_up(&(*stack), 0, &(*c));
	(*stack) = (*stack)->next;
	free(tmp);
	if (!ft_add_comand(&(*c), "rb\n"))
		ft_clean_up(&(*stack), 0, &(*c));
}

void		ft_rrb(t_stack **stack, t_comand_list **c)
{
	t_stack *tmp;
	t_stack *new_head;

	if (stack == 0 || *stack == 0)
		ft_clean_up(&(*stack), 0, &(*c));
	tmp = (*stack);
	while (tmp->next->next)
		tmp = tmp->next;
	if (!(new_head = ft_new_node(tmp->next->num, tmp->next->grup)))
		ft_clean_up(&(*stack), 0, &(*c));
	free(tmp->next);
	tmp->next = 0;
	new_head->next = (*stack);
	(*stack) = new_head;
	if (!ft_add_comand(&(*c), "rrb\n"))
		ft_clean_up(&(*stack), 0, &(*c));
}
