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

#include "randomizer.h"

size_t		ft_strlen(const char *s)
{
	size_t res;

	res = 0;
	while (*s != '\0' && ++res)
		s++;
	return (res);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (res == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < ft_strlen(s1))
		res[i] = s1[i];
	while (++j < ft_strlen(s2))
		res[i++] = s2[j];
	res[i] = ' ';
	res[i + 1] = 0;
	free(s1);
	free(s2);
	return (res);
}

static int	n_len(unsigned int n, char minus)
{
	int res;

	res = 1;
	if (n == 0)
		return (2);
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (minus == '+' ? res : res + 1);
}

static char	*make_str(unsigned int n, char *res, int n_len, char minus)
{
	n_len--;
	res[n_len] = '\0';
	n_len--;
	while (n_len >= 0)
	{
		res[n_len] = n % 10 + 48;
		n = n / 10;
		n_len--;
	}
	if (minus == '-')
		res[0] = '-';
	return (res);
}

char		*ft_itoa(int n)
{
	char			*res;
	unsigned int	rem_n;
	char			minus;

	minus = '+';
	if (n == -2147483648)
	{
		rem_n = n;
		minus = '-';
	}
	else if (n < 0)
	{
		rem_n = n * -1;
		minus = '-';
	}
	else
		rem_n = n;
	res = (char*)malloc(sizeof(char) * (n_len(rem_n, minus) + 1));
	if (res == NULL)
		return (res);
	return (make_str(rem_n, res, n_len(rem_n, minus), minus));
}
