NAME		= get_next_line.a
CC			= cc
AR			= ar rcs
RM			= rm -f
ifndef BUFFER_SIZE
BUFFER_SIZE	= 42
endif
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE)

SRCS		= get_next_line.c get_next_line_utils.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
