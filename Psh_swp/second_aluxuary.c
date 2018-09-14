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

int			ft_stack_len(t_stack *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int			ft_atoi(char *str)
{
	int					minus;
	unsigned long int	result;

	minus = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if ((result > 922337203685477580 || (result == 922337203685477580
		&& (*str - '0') > 7)) && minus == 1)
			return (-1);
		if ((result > 922337203685477580 || (result == 922337203685477580
		&& (*str - '0') > 8)) && minus == -1)
			return (0);
		result = result * 10 + (*str - 48);
		str++;
	}
	return ((int)(result * minus));
}

void		ft_clean_t_stack(t_stack **stack)
{
	t_stack *tmp;

	while (*stack)
	{
		tmp = (*stack);
		*stack = (*stack)->next;
		free(tmp);
		tmp = 0;
	}
	(*stack) = 0;
}

void		ft_clean_t_comand(t_comand_list **com)
{
	t_comand_list *tmp;

	while ((*com)->prev)
		(*com) = (*com)->prev;
	while (*com)
	{
		tmp = *com;
		*com = (*com)->next;
		free(tmp);
		tmp = 0;
	}
}

void		ft_clean_up(t_stack **a, t_stack **b, t_comand_list **c)
{
	if (a && (*a))
		ft_clean_t_stack(&(*a));
	if (b && (*b))
		ft_clean_t_stack(&(*b));
	if (c && (*c))
		ft_clean_t_comand(&(*c));
	exit(0);
}
