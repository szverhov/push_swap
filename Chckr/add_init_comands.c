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

int		ft_init_comands(t_comand_list **comands)
{
	if (!((*comands) = (t_comand_list*)malloc(sizeof(t_comand_list))))
		return (0);
	(*comands)->comand = "";
	(*comands)->next = 0;
	(*comands)->prev = 0;
	return (1);
}

int		ft_strlen1(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *str)
{
	char	*res;
	int		i;

	res = (char*)malloc(sizeof(char) * ft_strlen1(str) + 1);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

int		ft_add_comand(t_comand_list **comands, char **str)
{
	if (!((*comands)->next = (t_comand_list*)malloc(sizeof(t_comand_list))))
		return (0);
	(*comands)->next->comand = ft_strcpy(*str);
	(*comands)->next->next = 0;
	(*comands)->next->prev = (*comands);
	(*comands) = (*comands)->next;
	return (1);
}
