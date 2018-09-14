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

char	**ft_init_arr_comands(void)
{
	char	**arr_comands;

	arr_comands = (char**)malloc(sizeof(char*) * 12);
	arr_comands[0] = "pa";
	arr_comands[1] = "pb";
	arr_comands[2] = "sa";
	arr_comands[3] = "sb";
	arr_comands[4] = "ra";
	arr_comands[5] = "rra";
	arr_comands[6] = "rb";
	arr_comands[7] = "rrb";
	arr_comands[8] = "ss";
	arr_comands[9] = "rr";
	arr_comands[10] = "rrr";
	arr_comands[11] = 0;
	return (arr_comands);
}

t_func	*ft_init_funcs(void)
{
	t_func *funcs;

	funcs = malloc(sizeof(t_func) * 12);
	funcs[0] = ft_pa;
	funcs[1] = ft_pb;
	funcs[2] = ft_sa;
	funcs[3] = ft_sb;
	funcs[4] = ft_ra;
	funcs[5] = ft_rra;
	funcs[6] = ft_rb;
	funcs[7] = ft_rrb;
	funcs[8] = ft_ss;
	funcs[9] = ft_rr;
	funcs[10] = ft_rrr;
	funcs[11] = 0;
	return (funcs);
}

void	ft_in(t_stack **a, t_stack **b, t_comand_list **list)
{
	if (ft_is_sorted(*a) == 1)
		ft_printf("%s\n", "OK");
	else
		ft_printf("%s\n", "KO");
	clean_up(&(*a), &(*b), &(*list));
}

void	ft_sort(t_stack **a, t_comand_list **list, char **argv)
{
	t_stack		*b;
	char		**comands;
	t_func		*funcs;
	int			i;

	b = 0;
	comands = ft_init_arr_comands();
	funcs = ft_init_funcs();
	while ((*list)->prev)
		(*list) = (*list)->prev;
	if ((*list)->next)
		(*list) = (*list)->next;
	while ((*list))
	{
		i = -1;
		while (comands[++i])
			if (ft_strcmp(comands[i], (*list)->comand) == 0)
				funcs[i](&(*a), &b, &(*list), argv);
		if ((*list)->next == 0)
			break ;
		*list = (*list)->next;
	}
	free(funcs);
	free(comands);
	ft_in(&(*a), &b, &(*list));
}
