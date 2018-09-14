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

void	ft_check_revers(t_stack **a, t_stack **b, t_comand_list **comands)
{
	t_stack *tmp;
	t_stack *tmp_in;
	int		flag;

	flag = 0;
	tmp = (*b);
	if (!(*b))
		return ;
	while (tmp->next)
	{
		tmp_in = tmp->next;
		while (tmp_in)
		{
			if (tmp->num < tmp_in->num)
				flag = 1;
			tmp_in = tmp_in->next;
		}
		tmp = tmp->next;
	}
	if (flag == 0)
		while (*b)
		{
			ft_pa(&(*a), &(*b), &(*comands));
			(*a)->grup = -1;
		}
}
