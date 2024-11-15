NAME = gnlxio.a

SRC = get_next_line.c \
	get_next_line_utils.c \
	ft_readlines.c

OBJ = $(SRC:.c=.o)

CCA = cc -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c
	$(CCA) -o $@ -c $^

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
