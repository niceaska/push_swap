CC = gcc
NAME_CHECKER = checker
NAME = push_swap
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ./libft/
LIBFT_INC = includes/
CHECKER_SRCS = free.c checks.c print.c checker.c moves.c utils.c stack.c helpers.c
CHECKER_OBJ = $(CHECKER_SRCS:.c=.o)
PS_SRCS = mainsort.c free.c checks.c print.c  moves.c utils.c stack.c quicksort.c ops.c tools.c push_swap.c minisort.c helpers.c
PS_OBJS = $(PS_SRCS:.c=.o)

all: $(NAME)

$(NAME_CHECKER):
	make -C libft
	$(CC) $(CFLAGS) -c $(CHECKER_SRCS) -I $(LIBFT_DIR)$(LIBFT_INC)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) -o  $(NAME_CHECKER) -L libft/ -lft

$(NAME): $(NAME_CHECKER)
	$(CC) $(CFLAGS) -c $(PS_SRCS) -I $(LIBFT_DIR)$(LIBFT_INC)
	$(CC) $(CFLAGS) $(PS_OBJS) -o $(NAME) -L libft/ -lft

clean:
	make clean -C ./libft
	rm -f $(PS_OBJS)
	rm -f $(CHECKER_OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)
	rm -f $(NAME_CHECKER)

re: fclean all

.PHONY: clean fclean all re