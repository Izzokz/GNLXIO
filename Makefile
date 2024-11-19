NAME = gnlxio.a

SRC = gnlxio_ft_strdup.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_readlines.c \
	ft_free_rlines.c \
	ft_deline.c \
	ft_rewrite_file.c \
	ft_get_line.c \
	ft_len.c \
	ft_fix_lineno.c

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
