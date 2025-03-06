NAME 		= push_swap
BONUS		= checker
CC		= cc
CFLAGS 		= -Wall -Wextra -Werror
SRCS		= push_swap.c stacks.c switch.c \
		  checks.c rotate.c rrotate.c \
		  turks.c error.c actions.c sort.c \
		  index.c numberofchosen.c  \
	          ft_printf/ft_printf.c ft_printf/ft_printf_utils.c \
		  
BONUSSRCS	= push_swap_bonus.c push_swap_bonus_utils.c error.c \
		  stacks.c switch.c checks.c rotate.c rrotate.c \
		  ft_printf/ft_printf.c ft_printf/ft_printf_utils.c \
       		  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \

LIBFT		= libft/libft.a
DIR_LIBFT	= libft

all: $(NAME)

$(NAME): $(SRCS)
	make -C $(DIR_LIBFT) -s
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

bonus: $(BONUSSRCS)
	make -C $(DIR_LIBFT) -s
	$(CC) $(CFLAGS) $(BONUSSRCS) $(LIBFT) -o $(BONUS)
clean:
	make -s -C $(DIR_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)
	make -s -C $(DIR_LIBFT) fclean

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean bonus re rebonus
