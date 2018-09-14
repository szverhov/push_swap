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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
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

int					ft_count_of_biggest(t_stack *stack, int midl);
int					ft_count_of_lowest(t_stack *stack, int midl);
int					ft_find_lowest_in_row(t_stack *stack);
int					ft_find_biggest_in_row(t_stack *stack);
void				ft_print_exit(t_stack **a, t_stack **b,
	t_comand_list **com);
void				ft_easy_sort(t_stack **a, t_stack **b, t_comand_list **com);
t_stack				*ft_get_last(t_stack *stack);
int					ft_new_grup(t_stack *a, t_stack *b);
int					ft_find_midl_in_grup(t_stack *stack, int count);
int					ft_grup_len(t_stack *stack);
int					ft_booble_sort(int *arr, int count);
void				ft_check_revers(t_stack **a, t_stack **b,
	t_comand_list **comands);
void				ft_in_sort_triple_a(t_stack **a, t_comand_list **comands);
void				ft_in_sort_triple_b(t_stack **a,
	t_stack **b, t_comand_list **comands);
void				ft_quick_sort_a(t_stack **a,
	t_stack **b, t_comand_list **comands);
void				ft_quick_sort_b(t_stack **a,
	t_stack **b, t_comand_list **comands);
void				ft_remove_comands(t_comand_list **com);
void				ft_remove_pa_pb(t_comand_list **comands);
void				ft_remove_pb_pa(t_comand_list **comands);
void				ft_remove_rb_rrb(t_comand_list **comands);
void				ft_remove_rra_ra(t_comand_list **comands);
void				ft_remove_rrb_rb(t_comand_list **comands);
int					ft_smart_triple_b(t_stack **a, t_stack **b,
	t_comand_list **comands);
void				ft_magic_for_first_division(t_stack **a, int *midl,
	t_comand_list **comands);
t_stack				*ft_new_node(int i, int grup);
int					ft_add_node(t_stack **stack, int i, int grup);
int					ft_push_swap(char **argv, int argc, int flag);
void				ft_ra(t_stack **stack, t_comand_list **c);
void				ft_rra(t_stack **stack, t_comand_list **c);
void				ft_sb(t_stack **stack, t_comand_list **c);
void				ft_rb(t_stack **stack, t_comand_list **c);
void				ft_rrb(t_stack **stack, t_comand_list **c);
void				ft_pa(t_stack **a, t_stack **b, t_comand_list **c);
void				ft_pb(t_stack **b, t_stack **a, t_comand_list **c);
void				ft_sa(t_stack **stack, t_comand_list **c);
int					ft_stack_len(t_stack *stack);
int					ft_atoi(char *str);
void				ft_clean_t_stack(t_stack **stack);
void				ft_clean_t_comand(t_comand_list **com);
void				ft_clean_up(t_stack **a, t_stack **b, t_comand_list **c);
int					ft_init_comands(t_comand_list **comands);
int					ft_add_comand(t_comand_list **comands, char *str);
int					ft_comands_len(t_comand_list *com);
int					ft_strequ(char const *s1, char const *s2);
void				ft_write_comands(t_comand_list *com);
int					ft_strcmp(char *s1, const char *s2);
int					ft_str_len(char *str);
char				**ft_strsplit(char *s, char c);
void				ft_swap_from_b(t_stack **a, t_stack **b,
	t_comand_list **c, int grp);
int					ft_count_of_words(char **argv);
int					ft_is_sorted(t_stack **stack);
void				ft_quick_sort_a_in(t_stack **a, t_stack **b,
	t_comand_list **comands);
void				ft_quick_sort_a_in1(t_stack **a, t_stack **b,
	t_comand_list **comands, int *midl);
void				ft_swap_from_a_in(t_comand_list **c, t_stack **b,
	t_stack *tmp_a, t_stack *tmp_b);
t_stack				*ft_get_last_in_row(t_stack *stack);
void				ft_check_last_nums_in(t_stack *tmp_a,
	t_stack *tmp_b, int *flag, t_stack **a);
void				ft_check_last_nums(t_stack **a,
	t_stack **b, t_comand_list **comands);
int					ft_find_midl_in_grup1(t_stack *stack, int count);
int					ft_booble_sort1(int *arr, int count);
void				ft_quick_sort_b_in(t_stack **b, int *midl, int *count);
void				ft_clean_argv(char **argv);
int					ft_strcmp_spec(char *s1, const char *s2);

#endif
