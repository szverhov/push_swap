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

int		ft_strlen_int(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		res++;
		i++;
		while (str[i] == '0')
			i++;
		if (str[i] == '\0')
			i--;
	}
	while (str[i])
	{
		i++;
		res++;
	}
	return (res);
}

int		ft_count_of_words(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
