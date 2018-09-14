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

NAME = randomizer

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES = randomizer.c aluxuary.c aluxuary2.c

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
