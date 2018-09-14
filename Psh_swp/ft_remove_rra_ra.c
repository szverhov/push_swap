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

static	void	ft_in_rra_ra(t_comand_list **comands, int count)
{
	int				i;
	t_comand_list	*tmp;

	i = count;
	while (ft_strequ((*comands)->comand, "rra\n") == 1)
		(*comands) = (*comands)->next;
	tmp = (*comands)->prev;
	while (i--)
	{
		tmp->comand = "";
		tmp = tmp->prev;
		(*comands)->comand = "";
		(*comands) = (*comands)->next;
	}
}

static	void	ft_some_inner(t_comand_list **com, int *pb, int *flag)
{
	(*com) = (*com)->next;
	while (*com && ft_strequ((*com)->comand, "ra\n") == 1)
	{
		(*pb)++;
		(*com) = (*com)->next;
	}
	(*flag) = 1;
}

void			ft_remove_rra_ra(t_comand_list **comands)
{
	int				pa;
	int				pb;
	t_comand_list	*com;
	int				flag;

	flag = 0;
	com = *comands;
	pa = 0;
	pb = 0;
	while (com && ft_strequ(com->comand, "rra\n") == 1)
	{
		pa++;
		if (com->next && ft_strequ(com->next->comand, "ra\n") == 1)
			ft_some_inner(&com, &pb, &flag);
		if (flag == 1)
			break ;
		if (com)
			com = com->next;
	}
	if (pa == 0 || pb == 0)
		return ;
	pa = pa >= pb ? pb : pa;
	ft_in_rra_ra(&(*comands), pa);
}
