# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 17:36:40 by bel-oirg          #+#    #+#              #
#    Updated: 2023/12/10 12:20:56 by bel-oirg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c putstr_len.c putchar_len.c putnbr_len.c putnbr_len_u.c putnbr_len_p.c

OBJS = $(SRCS:.c=.o)

CC = cc

CCF = -Wall -Wextra -Werror

AR = ar rc

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c ft_printf.h
	$(CC) -c $(CCF) $<

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
