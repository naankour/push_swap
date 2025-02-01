NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = push_swap.c\
	algorithmes/algo_2.c\
	algorithmes/algo_3.c\
	algorithmes/algo_5.c\
	algorithmes/algo_n.c\
	instructions/push.c\
	instructions/reverse_rotate.c\
	instructions/rotate.c\
	instructions/swap.c\
	utils/error.c\
	utils/ft_split.c\
	utils/ft_strchr.c\
	utils/ft_strlen.c\
	utils/listes.c

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
