NAME_PS	=	push_swap
NAME_CK	=	checker
SRCDIR	=	./srcs
SRCLIST	=	check_argv.c \
			load_stack.c \
			check_issorted.c \
			exec_command.c \
			print_result.c \
			malloc_free_utils.c \
			dlst_utils.c \
			dlst_utils2.c \
			enum_utils.c
PS_LIST	=	push_swap.c \
			solve.c \
			solve_smallcase.c \
			solve_bigcase.c \
			solve_bigcase_utils.c \
			solve_bigcase_utils2.c \
			solve_bigcase_utils3.c
CK_LIST	=	checker.c
GNLDIR	=	./get_next_line
GNLLIST	=	get_next_line_bonus.c \
			get_next_line_utils_bonus.c
SRCS_PS	=	$(addprefix $(SRCDIR)/, $(PS_LIST)) \
			$(addprefix $(SRCDIR)/, $(SRCLIST)) \
			$(addprefix $(GNLDIR)/, $(GNLLIST))
SRCS_CK	=	$(addprefix $(SRCDIR)/, $(CK_LIST)) \
			$(addprefix $(SRCDIR)/, $(SRCLIST)) \
			$(addprefix $(GNLDIR)/, $(GNLLIST))
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

all: $(NAME_PS) $(NAME_CK)

clean:
	make clean -C $(LIBDIR)
	rm -f $(OBJS_PS)
	rm -f $(OBJS_CK)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME_PS)
	rm -f $(NAME_CK)

re: fclean all 

bonus: all 

.PHONY: all clean fclean re bonus
