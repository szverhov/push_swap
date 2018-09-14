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

static	void	ft_in_pa_pb(t_comand_list **comands, int count)
{
	int				i;
	t_comand_list	*tmp;

	i = count;
	if (count > 0)
	{
		while (ft_strequ((*comands)->comand, "pa\n") == 1)
			(*comands) = (*comands)->next;
		tmp = (*comands)->prev;
		while (i--)
		{
			tmp->comand = "";
			tmp = tmp->prev;
			(*comands)->comand = "";
			if ((*comands)->next)
				(*comands) = (*comands)->next;
		}
	}
}

void			ft_remove_pa_pb(t_comand_list **comands)
{
	int				pa;
	int				pb;
	t_comand_list	*com;

	com = *comands;
	pa = 0;
	pb = 0;
	while (com && ft_strequ(com->comand, "pa\n") == 1)
	{
		pa++;
		if (com->next && ft_strequ(com->next->comand, "pb\n") == 1)
		{
			com = com->next;
			while (com && ft_strequ(com->comand, "pb\n") == 1)
			{
				pb++;
				com = com->next;
			}
		}
		com = (com == 0 ? 0 : com->next);
	}
	if (pa == 0 || pb == 0)
		return ;
	pa = pa > pb ? pb : pa;
	ft_in_pa_pb(&(*comands), pa);
}
