NAME		= push_swap
BONUS		= checker_mac
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS_A		= srcs/array.c \
			srcs/main.c \
			srcs/push_swap.c \
			srcs/push_swap_utils.c \
			srcs/sort_rotate_utils.c \
			srcs/sort_rotate.c \
			srcs/sort_utils.c \
			srcs/sort.c \
			srcs/stack_utils.c \
			srcs/subject_functions_push_swap.c \
			srcs/subject_functions_reverse_rotate.c \
			srcs/subject_functions_rotate.c

SRCS_B		= srcs/checker_bonus.c \
			srcs/push_swap_utils.c \
			srcs/get_next_line.c \
			srcs/stack_utils.c \
			srcs/subject_functions_push_swap_bonus.c \
			srcs/subject_functions_reverse_rotate_bonus.c \
			srcs/subject_functions_rotate_bonus.c

OBJS_A		= $(SRCS_A:%.c=%.o)

OBJS_B		= $(SRCS_B:.c=.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

ifdef WITH_BONUS
OBJS = $(OBJS_B)
NAME = $(BONUS)
else
OBJS = $(OBJS_A)
endif

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		gcc -o $(NAME) $(OBJS) -Llibft -lft

bonus		:
	@make WITH_BONUS=1 all

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS_A) $(OBJS_B)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(BONUS)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re bonus
