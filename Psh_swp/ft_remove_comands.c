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

void	ft_remove_comands(t_comand_list **com)
{
	while ((*com)->prev)
		(*com) = (*com)->prev;
	while ((*com)->next)
	{
		if ((*com) && ft_strequ((*com)->comand, "pa\n") == 1)
			ft_remove_pa_pb(&(*com));
		if ((*com) && ft_strequ((*com)->comand, "pb\n") == 1)
			ft_remove_pb_pa(&(*com));
		if ((*com) && ft_strequ((*com)->comand, "rra\n") == 1)
			ft_remove_rra_ra(&(*com));
		if ((*com) && ft_strequ((*com)->comand, "rrb\n") == 1)
			ft_remove_rrb_rb(&(*com));
		if ((*com) && ft_strequ((*com)->comand, "rb\n") == 1)
			ft_remove_rb_rrb(&(*com));
		if ((*com)->next)
			(*com) = (*com)->next;
	}
}
