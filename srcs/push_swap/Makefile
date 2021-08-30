NAME	=	push_swap
SRCS	=	push_swap.c
INCLUDE	=	-I ../../includes
OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAG) $(INCLUDE) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(INCLUDE) -o $@ $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
