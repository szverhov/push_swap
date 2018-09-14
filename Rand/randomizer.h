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

#ifndef RANDOMIZER_H
# define RANDOMIZER_H

# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct	s_random
{
	int		i;
	int		j;
	int		stime;
	long	ltime;
	int		rem;
	int		div;
	int		ran;
	int		res[500];
	int		flag;
	char	*p_s;
	char	*checker;
	char	*nums;
	char	*wc_l;
	char	*nums2;
	char	*p_s2;
}				t_random;

size_t			ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_itoa(int n);
char			*ft_strcpy(char *dst, const char *src);
int				ft_atoi(const char *str);

#endif
