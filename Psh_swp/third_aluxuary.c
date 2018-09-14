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

int		ft_init_comands(t_comand_list **comands)
{
	if (!((*comands) = (t_comand_list*)malloc(sizeof(t_comand_list))))
		return (0);
	(*comands)->comand = "start";
	(*comands)->next = 0;
	(*comands)->prev = 0;
	return (1);
}

int		ft_add_comand(t_comand_list **comands, char *str)
{
	if (!((*comands)->next = (t_comand_list*)malloc(sizeof(t_comand_list))))
		return (0);
	(*comands)->next->comand = str;
	(*comands)->next->next = 0;
	(*comands)->next->prev = (*comands);
	(*comands) = (*comands)->next;
	return (1);
}

int		ft_comands_len(t_comand_list *com)
{
	int res;

	res = 0;
	while (com->prev)
		com = com->prev;
	com = com->next;
	while (com)
	{
		if (com->comand[0] != 0)
			res++;
		com = com->next;
	}
	return (res);
}

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if ((!(s1)) || (!(s2)))
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

void	ft_write_comands(t_comand_list *com)
{
	while (com->prev)
		com = com->prev;
	com = com->next;
	while (com)
	{
		if (ft_strequ(com->comand, "") == 1)
		{
			com = com->next;
			continue ;
		}
		ft_printf("%s", com->comand);
		com = com->next;
	}
}
