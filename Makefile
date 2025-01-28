
NAME 		= push_swap
BONUS		= checker
CC			= gcc
FLAGS 		= -Wall -Wextra -Werror
SRCS		= push_swap.c push_swap_utils.c stacks.c push.c \
		  checks.c

OBJS		:= $(SRCS:.c=.o)

AR_LIBFT	= libft/libft.a
DIR_LIBFT	= libft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(DIR_LIBFT) -s
	$(CC) $(FLAGS) $(OBJS) $(AR_LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BNS)
	make -s -C $(DIR_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -s -C $(DIR_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean bonus re