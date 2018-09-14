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

void	ft_magic_for_first_division(t_stack **a, int *midl,
	t_comand_list **comands)
{
	int		count;
	t_stack *tmp;
	t_stack *tmp_in;

	tmp = *a;
	count = ft_grup_len(*a) / 2;
	while (count--)
		tmp = tmp->next;
	while (tmp)
	{
		tmp_in = tmp->next;
		while (tmp_in)
		{
			if (tmp->num > tmp_in->num)
				break ;
			tmp_in = tmp_in->next;
		}
		if (tmp_in == 0)
			count++;
		tmp = tmp->next;
	}
	if (count >= ft_grup_len(*a) / 3)
		while ((*a)->grup == 0 && ft_get_last(*a)->num <= *midl)
			ft_rra(&(*a), &(*comands));
}

int		ft_is_sortedd(t_stack *stack)
{
	t_stack *tmp;

	while (stack->next)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->num > tmp->num)
			{
				ft_printf("%d %d\n", stack->num, tmp->num);
				return (0);
			}
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}
