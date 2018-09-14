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

static char	*ft_strsubb(char *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;
	unsigned int	end;

	if (s == NULL)
		return (NULL);
	res = (char*)malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	end = start + len;
	while (start < end)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = 0;
	return (res);
}

int			count_of_words(char *s, char c)
{
	size_t i;
	size_t w_count;

	if (s == 0)
		return (0);
	w_count = 0;
	i = 0;
	if (s[0] != c)
		w_count++;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != 0))
			w_count++;
		i++;
	}
	return (w_count);
}

char		**ft_strsplit(char *s, char c)
{
	char		**res;
	int			j;
	int			len;
	int			i;

	j = 0;
	len = 0;
	i = -1;
	if (s == 0 || (res = (char**)malloc(sizeof(char*)
		* (count_of_words(s, c) + 1))) == 0)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c || (s[i + 1] == 0 && s[i] != c))
			len++;
		if ((s[i] == c && len > 0) || (s[i + 1] == 0 && len > 0))
		{
			res[j] = (s[i + 1] == 0 && s[i] != c) ?
			ft_strsubb(s, i - len + 1, len) : ft_strsubb(s, i - len, len);
			j++;
			len = 0;
		}
	}
	res[j] = 0;
	return (res);
}
