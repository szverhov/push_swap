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

int		ft_check_shit(char *s1, const char *s2)
{
	if (*s1 == '-' || *s1 == '+')
		s1++;
	if (*s2 == '-' || *s2 == '+')
		s2++;
	if (*s1 == '0' && *(s1 + 1) != '\0')
		while (*s1 == '0' && *(s1 + 1) != '\0')
			s1++;
	if (*s2 == '0' && *(s2 + 1) != '\0')
		while (*s2 == '0' && *(s2 + 1) != '\0')
			s2++;
	if (*s1 == '0' && *s2 == '0')
		return (0);
	return (1);
}

int		ft_strcmp_spec(char *s1, const char *s2)
{
	if (!ft_check_shit(s1, s2))
		return (0);
	if ((*s1 == '+' && *s2 != '-'))
		s1++;
	if ((*s2 == '+' && *s1 != '-'))
		s2++;
	if ((*s1 == '-' && *s2 == '-') || (*s1 == '+' && *s2 == '+'))
	{
		s1++;
		s2++;
	}
	if (*s1 == '0' && *(s1 + 1) != '\0')
		while (*s1 == '0' && *(s1 + 1) != '\0')
			s1++;
	if (*s2 == '0' && *(s2 + 1) != '\0')
		while (*s2 == '0' && *(s2 + 1) != '\0')
			s2++;
	while ((unsigned char)*s1 != 0 || (unsigned char)*s2 != 0)
	{
		if ((unsigned char)*s1 - (unsigned char)*s2 != 0)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}
