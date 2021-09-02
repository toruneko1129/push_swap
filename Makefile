NAME_PS	=	push_swap
NAME_CK	=	checker
SRCDIR	=	./srcs
SRCLIST	=	check_argv.c \
			load_stack.c \
			check_issorted.c \
			print_error_exit.c \
			malloc_free_utils.c \
			dlst_utils.c \
			dlst_utils2.c
PS_LIST	=	push_swap.c \
			solve.c
CK_LIST	=	checker.c
SRCS_PS	=	$(addprefix $(SRCDIR)/, $(PS_LIST)) \
			$(addprefix $(SRCDIR)/, $(SRCLIST))
SRCS_CK	=	$(addprefix $(SRCDIR)/, $(CK_LIST)) \
			$(addprefix $(SRCDIR)/, $(SRCLIST))
OBJS_PS	=	$(SRCS_PS:.c=.o)
OBJS_CK	=	$(SRCS_CK:.c=.o)
INCLUDE	=	-I ./includes
LIBDIR	=	./libft
LIBFT	=	$(LIBDIR)/libft.a
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAG) $(INCLUDE) -o $@ -c $<

$(NAME_PS): $(OBJS_PS)
	make bonus -C $(LIBDIR)
	$(CC) $(CFLAG) $(INCLUDE) -o $@ $^ $(LIBFT)

$(NAME_CK): $(OBJS_CK)
	make bonus -C $(LIBDIR)
	$(CC) $(CFLAG) $(INCLUDE) -o $@ $^ $(LIBFT)

all: $(NAME_PS)

clean:
	make clean -C $(LIBDIR)
	rm -f $(OBJS_PS)
	rm -f $(OBJS_CK)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME_PS)
	rm -f $(NAME_CK)

re: fclean $(NAME_PS)

bonus: $(NAME_PS) $(NAME_CK)

.PHONY: all clean fclean re bonus
