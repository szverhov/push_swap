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

void		ft_pb(t_stack **a, t_stack **b, t_comand_list **c, char **argv)
{
	t_stack *new_head;
	t_stack *tmp;

	if (!a || !(*a))
		return ;
	if (!(new_head = ft_new_node((*a)->num, (*a)->grup)))
		clean_up(&(*a), &(*b), &(*c));
	new_head->next = (*b);
	(*b) = new_head;
	tmp = (*a)->next;
	free(*a);
	*a = tmp;
	if (ft_strcmp(argv[1], "-c") == 0 || ft_strcmp(argv[2], "-c") == 0)
		ft_colors("pb");
	ft_print_stacks(*a, *b, argv);
}
