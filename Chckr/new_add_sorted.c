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

t_stack		*ft_new_node(int i, int grup)
{
	t_stack *stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	stack->num = i;
	stack->grup = grup;
	stack->next = 0;
	return (stack);
}

int			ft_add_node(t_stack **stack, int i, int grup)
{
	t_stack *tmp;

	if (stack == 0 || *stack == 0)
		return (0);
	tmp = (*stack);
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = ft_new_node(i, grup)))
		return (0);
	return (1);
}

int			ft_is_sorted(t_stack *stack)
{
	t_stack *tmp;

	if (!stack)
		return (0);
	while (stack->next)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->num > tmp->num)
			{
				return (0);
			}
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}
