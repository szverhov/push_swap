# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szverhov <szverhov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/07 09:08:03 by szverhov          #+#    #+#              #
#    Updated: 2017/11/06 12:25:29 by szverhov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES = aluxuary_four.c counts.c easy_sort.c first_aluxuary.c ft_check_revers.c ft_in_sort_triple_a.c \
	ft_in_sort_triple_b.c ft_main.c ft_quick_sort_a.c ft_quick_sort_b.c ft_remove_comands.c ft_remove_pa_pb.c \
	ft_remove_pb_pa.c ft_remove_rb_rrb.c ft_remove_rra_ra.c ft_remove_rrb_rb.c ft_smart_triple_b.c ft_strsplit.c \
	magic.c node_funcs.c push_swap.c rrb_rb_sb_rra_ra.c sa_pb_pa.c second_aluxuary.c third_aluxuary.c ft_quick_sort_a_inners.c \
	ft_quick_sort_b_iners.c ft_clean_argv.c

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L. -lftprintf -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
