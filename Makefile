# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 20:25:03 by rtulchiy          #+#    #+#              #
#    Updated: 2018/02/03 12:46:25 by rtulchiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PSDIR = Psh_swp

CHECKERDIR = Chckr

RANDDIR = Rand

all:
	make -C $(PSDIR)
	make -C $(CHECKERDIR)
	make -C $(RANDDIR)
	mv ./$(PSDIR)/push_swap ./
	mv ./$(CHECKERDIR)/checker ./
	mv ./$(RANDDIR)/randomizer ./
clean:
	make clean -C $(PSDIR)
	make clean -C $(CHECKERDIR)
	make clean -C $(RANDDIR)
fclean: clean
	rm -f push_swap checker randomizer
re: fclean all
