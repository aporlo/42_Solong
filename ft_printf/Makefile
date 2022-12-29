# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 20:22:18 by lsomrat           #+#    #+#              #
#    Updated: 2022/08/22 04:18:04 by lsomrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a
SRCS	= ft_printf.c \
		  ft_putnbr.c \
		  ft_putstr.c \
		  ft_putptr.c \
		  ft_putunsigned.c \
		  ft_puthex.c

OBJS	= ${SRCS:.c=.o}

%.o: %.c
	gcc ${FLAGS} -c $< -o $@
	
$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

norminette:
	norminette ${SRCS}
	
all: ${NAME}

clean:
	rm -f ${OBJS}
	# rm -f ${OBJS} ${OBJS_B}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: norminette all
