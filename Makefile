NAME = gnlxio.a

MAINDIR = 000_MAIN/
UTILDIR = 100_UTILS/

MAINSRC = $(MAINDIR)get_next_line.c \
	$(MAINDIR)ft_readlines.c \
	$(MAINDIR)ft_deline.c \
	$(MAINDIR)ft_rewrite_file.c \
	$(MAINDIR)ft_get_line.c \
	$(MAINDIR)ft_readfile.c \
	$(MAINDIR)ft_replace.c \
	$(MAINDIR)ft_input.c \
	$(MAINDIR)ft_gen_file.c \
	$(MAINDIR)ft_add_line.c
UTILSSRC = $(UTILDIR)gnlxio_ft_strdup.c \
	$(UTILDIR)gnlxio_ft_putstr_fd.c \
	$(UTILDIR)get_next_line_utils.c \
	$(UTILDIR)ft_free_rlines.c \
	$(UTILDIR)ft_len.c \
	$(UTILDIR)ft_fix_lineno.c \
	$(UTILDIR)gnlxio_ft_strnstr.c \
	$(UTILDIR)gnlxio_ft_strcmp.c \
	$(UTILDIR)ft_rlines_dup.c \
	$(UTILDIR)ft_rlines_cutendl.c \
	$(UTILDIR)invalid_rlines.c \
	$(UTILDIR)ft_trunc.c \
	$(UTILDIR)ft_realloc_rlines.c

OBJDIR = 666_OBJ/
OBJ = $(patsubst %.c,$(OBJDIR)%.o,$(notdir $(MAINSRC) $(UTILSSRC)))

CCA = cc -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(MAINDIR)%.c | $(OBJDIR)
	$(CCA) -o $@ -c $<

$(OBJDIR)%.o: $(UTILDIR)%.c | $(OBJDIR)
	$(CCA) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
