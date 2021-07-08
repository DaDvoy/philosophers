NAME = philo

SRC = main.c parser.c start.c utils.c

OBJ = $(SRC:.c=.o)

HEADER = philo.h

CC = gcc -g -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
