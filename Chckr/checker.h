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

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct		s_stack
{
	int				num;
	int				grup;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_comand_list
{
	char					*comand;
	struct s_comand_list	*next;
	struct s_comand_list	*prev;
}					t_comand_list;

typedef void	(*t_func)(t_stack **a, t_stack **b,
	t_comand_list **c, char **argv);

char				**ft_strsplit(char *s, char c);
int					ft_atoi(char *str);
int					ft_strlen_int(char *s);
int					count_of_words(char *s, char c);
int					ft_checker(int argc, char **argv, int flag);
int					ft_is_sorted(t_stack *stack);
int					ft_add_node(t_stack **stack, int i, int grup);
t_stack				*ft_new_node(int i, int grup);
int					ft_strcmp(char *s1, const char *s2);
int					ft_count_of_words(char **argv);
int					ft_add_comand(t_comand_list **comands, char **str);
int					ft_init_comands(t_comand_list **comands);
void				ft_sort(t_stack **stack, t_comand_list **list, char **argv);
void				clean_up(t_stack **a, t_stack **b, t_comand_list **c);
int					ft_read_comands(t_comand_list **list, char **str);
void				ft_clean_prototypes(char **prototypes);
void				ft_sa(t_stack **a, t_stack **b, t_comand_list **c,
	char **argv);
void				ft_sb(t_stack **a, t_stack **b, t_comand_list **c,
	char **argv);
void				ft_ss(t_stack **a, t_stack **b, t_comand_list **c,
	char **argv);
void				ft_rr(t_stack **a, t_stack **b, t_comand_list **c,
	char **argv);
void				ft_rrr(t_stack **a, t_stack **b, t_comand_list **c,
	char **argv);
void				ft_ra(t_stack **a, t_stack **b, t_comand_list **c,
	char **argv);
void				ft_rra(t_stack **a, t_stack **b, t_comand_list **c,
	char **argv);
void				ft_rb(t_stack **a, t_stack **b, t_comand_list **c,
	char **argv);
void				ft_rrb(t_stack **a, t_stack **b, t_comand_list **c,
	char **argv);
void				ft_pa(t_stack **a, t_stack **b, t_comand_list **c,
	char **argv);
void				ft_pb(t_stack **a, t_stack **b, t_comand_list **c,
	char **argv);
void				ft_print_stacks(t_stack *a, t_stack *b, char **argv);
void				ft_colors(char *str);
void				ft_check_flags(char **argv, int *flag);
int					ft_strcmp_spec(char *s1, const char *s2);

#endif
