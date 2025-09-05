CC = cc
FLAG = -Wall -Wextra -Werror

NAME = push_swap

SRCS = 	push_swap.c \
		radix_sort.c \
		push_swap_utils.c \
		push_swap_input.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAG) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@ 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re