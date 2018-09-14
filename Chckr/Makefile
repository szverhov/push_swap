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

NAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES = main.c ft_strsplit.c get_next_line.c ft_atoi.c strlen_count_wrds.c checker.c new_add_sorted.c ft_strcmp.c add_init_comands.c sort.c \
		clean_up.c read_coms_init_prot.c sa_sb_rr_rrr_ss.c ra_rra_rb_rrb_pa.c pb.c ft_print_stacks.c

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L. -lftprintf -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
