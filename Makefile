NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = push_swap.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	cc -o $(NAME) $(OBJS)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
