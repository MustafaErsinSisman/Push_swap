
NAME 		= push_swap
BONUS		= checker
CC			= cc
FLAGS 		= -Wall -Wextra -Werror -g
SRCS		= push_swap.c stacks.c switch.c \
		  checks.c rotate.c rrotate.c \
		  turks.c \

LIBFT	= libft/libft.a
DIR_LIBFT	= libft

all: $(NAME)

$(NAME): $(SRCS)
	make -C $(DIR_LIBFT) -s
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME) -lm

clean:
	make -s -C $(DIR_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -s -C $(DIR_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean bonus re