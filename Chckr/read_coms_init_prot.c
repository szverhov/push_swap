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

void	ft_clean_prototypes(char **prototypes)
{
	int		i;
	char	*tmp;

	i = -1;
	while (prototypes[++i])
	{
		tmp = prototypes[i];
		free(tmp);
	}
	free(prototypes[i]);
	free(prototypes);
	get_next_line(-1234, 0);
}

int		ft_read_comands(t_comand_list **list, char **str)
{
	char	**prototypes;
	int		i;
	int		gnl;

	prototypes = ft_strsplit("pa pb sa sb ra rra rb rrb ss rr rrr", ' ');
	while ((gnl = get_next_line(0, &(*str))) > 0)
	{
		i = -1;
		ft_add_comand(&(*list), &(*str));
		while (prototypes[++i])
			if (ft_strcmp(prototypes[i], *str) == 0)
				break ;
		free(*str);
		(*str) = 0;
		if (prototypes[i] == 0)
		{
			ft_clean_prototypes(prototypes);
			ft_printf("%s\n", "Error");
			return (0);
		}
	}
	ft_clean_prototypes(prototypes);
	return (1);
}
