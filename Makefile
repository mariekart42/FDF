NAME = fdf
SRC = files/test_mlx.c

CFLAGS = -Wall -Wextra -Werror -Iincludes -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):
	$(MAKE) -C mlx
	$(CC) $(SRC) $(CFLAGS) $(NAME)
	@echo "Everything compiled successfully"

g:
	$(CC) $(SRC) $(CFLAGS) $(NAME)
	@echo "my shit compiled successfully"

clean:
	@$(RM) $(NAME)
	
fclean: clean
	@$(MAKE) clean -C mlx/
	
re: fclean all
# -Og -g3 -fsanitize=address