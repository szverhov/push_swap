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

void		ft_clean_t_stack(t_stack **stack)
{
	t_stack *tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
		tmp = 0;
	}
}

void		ft_clean_t_comand(t_comand_list **com)
{
	t_comand_list *tmp;

	while ((*com)->prev)
		(*com) = (*com)->prev;
	tmp = *com;
	*com = (*com)->next;
	free(tmp);
	while (*com)
	{
		tmp = *com;
		*com = (*com)->next;
		free(tmp->comand);
		free(tmp);
		tmp = 0;
	}
}

void		clean_up(t_stack **a, t_stack **b, t_comand_list **c)
{
	if (a && (*a))
		ft_clean_t_stack(&(*a));
	if (b && (*b))
		ft_clean_t_stack(&(*b));
	if (c && (*c))
		ft_clean_t_comand(&(*c));
	exit(0);
}
