CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
CHECKER = checker

SRC = main.c push_swap_gear/push_swap.c push_swap_gear/push.c \
	push_swap_gear/reverse_rotate.c push_swap_gear/rotate.c \
	push_swap_gear/sorter.c push_swap_gear/swap.c push_swap_gear/getter.c\
	push_swap_gear/errors_check.c push_swap_gear/push_swap_utils.c

B_SRC = checker.c Get_Next_Line/get_next_line.c \
	Get_Next_Line/get_next_line_utils.c push_swap_gear/errors_check.c \
	push_swap_gear/push_swap.c push_swap_gear/push.c \
	push_swap_gear/reverse_rotate.c push_swap_gear/rotate.c \
	push_swap_gear/swap.c

LIBFT = libft/ft_atoi.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c \
	libft/ft_lstsize.c libft/ft_lstlast.c libft/ft_lstnew.c

OBJS = $(SRC:.c=.o)
B_OBJS = $(B_SRC:.c=.o)
LIBFT_O = $(LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_O)
	$(CC) $(CFLAGS) $(LIBFT_O) $(OBJS) -o $(NAME)
clean:
	rm -f $(OBJS) $(B_OBJS) $(LIBFT_O)
fclean: clean
	rm -f $(NAME) $(CHECKER)
re: fclean all

bonus: $(B_OBJS) $(LIBFT_O)
	$(CC) $(CFLAGS) $(LIBFT_O) $(B_OBJS) -o $(CHECKER)