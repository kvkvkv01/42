# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caualves <caualves@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 16:17:40 by caualves          #+#    #+#              #
#    Updated: 2025/12/22 16:28:15 by caualves         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
       ft_handle_conversion.c \
       ft_print_char.c \
       ft_print_string.c \
       ft_print_pointer.c \
       ft_print_decimal.c \
       ft_print_unsigned.c \
       ft_print_hex.c \
       ft_putchar.c \
       ft_putnbr_base.c \
       ft_itoa.c \
       ft_utoa.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME)
	$(CC) -Wall -Wextra test_main.c -L. -lftprintf -o test_program

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test_program

re: fclean all

.PHONY: all clean fclean re test
