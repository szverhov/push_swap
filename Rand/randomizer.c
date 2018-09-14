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

void		ft_randoming(t_random **ran_obj)
{
	while ((*ran_obj)->i < 1000)
	{
		(*ran_obj)->flag = 0;
		(*ran_obj)->j = 0;
		while ((*ran_obj)->rem == 0)
			(*ran_obj)->rem = clock();
		(*ran_obj)->ran = rand() % (*ran_obj)->rem;
		if ((*ran_obj)->div % 10 == 0)
			(*ran_obj)->ran *= -1;
		while ((*ran_obj)->j < 500)
		{
			if ((*ran_obj)->res[(*ran_obj)->j] == (*ran_obj)->ran)
				(*ran_obj)->flag = 1;
			(*ran_obj)->j++;
		}
		if ((*ran_obj)->flag == 0)
			(*ran_obj)->res[(*ran_obj)->i++] = (*ran_obj)->ran;
		if ((*ran_obj)->i == 500)
			break ;
		(*ran_obj)->div -= 137 - clock() % clock() % 100;
		if ((*ran_obj)->div <= 0)
			(*ran_obj)->div = 10000;
	}
}

void		ft_init_variables(t_random **ran_obj)
{
	(*ran_obj)->ltime = time(NULL);
	(*ran_obj)->stime = (unsigned int)(*ran_obj)->ltime / 2;
	srand((*ran_obj)->stime);
	(*ran_obj)->i = 0;
	(*ran_obj)->div = clock();
	(*ran_obj)->rem = clock();
	(*ran_obj)->j = 0;
	while ((*ran_obj)->j < 500)
		(*ran_obj)->res[(*ran_obj)->j++] = -2147483648;
	(*ran_obj)->j = 0;
}

void		inner(t_random **ran_obj)
{
	write(1, "COUNT OF OPERATIONS :", 21);
	system((*ran_obj)->wc_l);
	write(1, "\n", 1);
	(*ran_obj)->nums = (char*)malloc(sizeof(char)
	* ft_strlen((*ran_obj)->nums2) + 1);
	(*ran_obj)->nums = ft_strcpy((*ran_obj)->nums, (*ran_obj)->nums2);
	(*ran_obj)->checker = ft_strjoin((*ran_obj)->checker, (*ran_obj)->nums2);
	(*ran_obj)->p_s = ft_strjoin((*ran_obj)->p_s2, (*ran_obj)->checker);
	write(1, "TEST NUMS : ", 12);
	write(1, (*ran_obj)->nums, ft_strlen((*ran_obj)->nums));
	write(1, "\n", 1);
	write(1, "-----------------------------", 32);
	write(1, "\n", 1);
	system((*ran_obj)->p_s);
	free((*ran_obj)->nums);
	free((*ran_obj)->p_s);
	free((*ran_obj)->wc_l);
	free(*ran_obj);
}

void		inner2(t_random **ran_obj)
{
	(*ran_obj)->nums2 = (char*)malloc(sizeof(char)
	* ft_strlen((*ran_obj)->nums) + 1);
	(*ran_obj)->nums2 = ft_strcpy((*ran_obj)->nums2, (*ran_obj)->nums);
	(*ran_obj)->p_s = ft_strjoin((*ran_obj)->p_s, (*ran_obj)->nums);
	(*ran_obj)->p_s2 = (char*)malloc(sizeof(char)
	* ft_strlen((*ran_obj)->p_s) + 1);
	(*ran_obj)->p_s2 = ft_strcpy((*ran_obj)->p_s2, (*ran_obj)->p_s);
	(*ran_obj)->wc_l = ft_strjoin((*ran_obj)->p_s, (*ran_obj)->wc_l);
}

int			main(int argc, char *argv[])
{
	t_random *ran_obj;

	if (argc == 1 || argc > 2)
		return (1);
	argc = ft_atoi(argv[1]);
	if (argc > 500 || argc < 1)
		return (1);
	ran_obj = (t_random*)malloc(sizeof(t_random));
	ft_init_variables(&ran_obj);
	ft_randoming(&ran_obj);
	ran_obj->p_s = (char*)malloc(sizeof(char) * 22);
	ran_obj->checker = (char*)malloc(sizeof(char) * 22);
	ran_obj->nums = (char*)malloc(sizeof(char) * 22);
	ran_obj->wc_l = (char*)malloc(sizeof(char) * 22);
	ft_strcpy(ran_obj->wc_l, "| wc -l");
	ft_strcpy(ran_obj->p_s, "./push_swap ");
	ft_strcpy(ran_obj->checker, "| ./checker ");
	ran_obj->nums[0] = 0;
	ran_obj->i = 0;
	while (ran_obj->i < argc)
		ran_obj->nums = ft_strjoin(ran_obj->nums,
		ft_itoa(ran_obj->res[ran_obj->i++]));
	inner2(&ran_obj);
	inner(&ran_obj);
	return (0);
}
