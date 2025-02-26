
NAME 		= push_swap
BONUS		= checker
CC		= cc
FLAGS 		= -Wall -Wextra -Werror -g
SRCS		= push_swap.c stacks.c switch.c \
		  checks.c rotate.c rrotate.c \
		  turks.c error.c actions.c sort.c \
		  index.c numberofchosen.c lastsort.c\
		  
BONUSSRCS	= push_swap_bonus.c push_swap_bonus_utils.c error.c\
		  stacks.c switch.c checks.c rotate.c rrotate.c \

LIBFT		= libft/libft.a
DIR_LIBFT	= libft

all: $(NAME)

$(NAME): $(SRCS)
	make -C $(DIR_LIBFT) -s
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)

bonus: $(BONUSSRCS)
	make -C $(DIR_LIBFT) -s
	$(CC) $(FLAGS) $(BONUSSRCS) $(LIBFT) -o $(BONUS)
clean:
	make -s -C $(DIR_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)
	make -s -C $(DIR_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean bonus re