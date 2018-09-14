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

#include "push_swap.h"

int		ft_count_of_words(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int		ft_str_len(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		res++;
		i++;
	}
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		i--;
	while (str[i])
	{
		i++;
		res++;
	}
	return (res);
}

int		ft_strcmp(char *s1, const char *s2)
{
	while ((unsigned char)*s1 != 0 || (unsigned char)*s2 != 0)
	{
		if ((unsigned char)*s1 - (unsigned char)*s2 != 0)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_swap_from_b(t_stack **a, t_stack **b, t_comand_list **c, int grp)
{
	ft_pa(&(*a), &(*b), &(*c));
	(*a)->grup = grp;
	if ((*a)->num > (*a)->next->num && ft_grup_len(*a) == 2)
		ft_sa(&(*a), &(*c));
}

int		ft_is_sorted(t_stack **s)
{
	t_stack *tmp;
	t_stack *stack;

	stack = (*s);
	while (stack->next)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->num > tmp->num)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	ft_clean_up(&(*s), 0, 0);
	return (1);
}
