NAME		= push_swap
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= srcs/array.c \
			srcs/main.c \
			srcs/push_swap.c \
			srcs/sort_rotate_utils.c \
			srcs/sort_rotate.c \
			srcs/sort_utils.c \
			srcs/sort.c \
			srcs/stack_utils.c \
			srcs/subject_functions_push_swap.c \
			srcs/subject_functions_reverse_rotate.c \
			srcs/subject_functions_rotate.c

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		gcc -o $(NAME) $(OBJS) -Llibft -lft

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re bonus
