SRCS = push_swap.c push_swap_utils.c 

BONUS = checker

OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUS:.c=.o)

NAME = pushswap

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) bonus
	ar rc $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUSOBJS)
	ar rc $(NAME) $(BONUSOBJS)

clean:
	rm -rf $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
