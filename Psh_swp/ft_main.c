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

int		main(int argc, char *argv[])
{
	if (argc == 1)
	{
		ft_printf("%s\n", "Error");
		return (0);
	}
	if (argc == 2)
	{
		ft_push_swap(ft_strsplit(argv[1], ' '), argc, 1);
		return (0);
	}
	else
		ft_push_swap(argv, argc, 0);
	return (0);
}
